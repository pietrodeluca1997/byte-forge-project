#include "application_window.hpp"

namespace BFE::Multimedia
{
    uint8_t IApplicationWindow::windowID = 0;

    const uint8_t IApplicationWindow::FetchNextID()
    {
        return windowID++;
    }
}