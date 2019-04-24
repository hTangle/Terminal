#include "pch.h"
#include "BaseWindow.h"
#include <winrt/Microsoft.Terminal.TerminalControl.h>
#include <winrt/Microsoft.Terminal.TerminalApp.h>

class IslandWindow : public BaseWindow<IslandWindow>
{
public:
    IslandWindow() noexcept;
    virtual ~IslandWindow() override;

    void MakeWindow() noexcept;

    void OnSize();

    LRESULT MessageHandler(UINT const message, WPARAM const wparam, LPARAM const lparam) noexcept;
    void ApplyCorrection(double scaleFactor);
    void NewScale(UINT dpi) override;
    void OnResize(const UINT width, const UINT height) override;
    void OnMinimize() override;
    void OnRestore() override;
    void SetRootContent(winrt::Windows::UI::Xaml::UIElement content);

    void Initialize();

    void SetCreateCallback(std::function<void(const HWND, const RECT)> pfn) noexcept;

private:

    void _InitXamlContent();

    unsigned int _currentWidth;
    unsigned int _currentHeight;
    HWND _interopWindowHandle;

    winrt::Windows::UI::Xaml::Hosting::DesktopWindowXamlSource _source;

    winrt::Windows::UI::Xaml::Media::ScaleTransform _scale;
    winrt::Windows::UI::Xaml::Controls::Grid _rootGrid;

    std::function<void(const HWND, const RECT)> _pfnCreateCallback;

    void _HandleCreateWindow(const WPARAM wParam, const LPARAM lParam) noexcept;
};
