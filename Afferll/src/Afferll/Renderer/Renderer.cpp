#include "AfrlPch.h"
#include "Afferll/Renderer/Renderer.h"


namespace Afferll
{
    RendererAPI Renderer::s_RendererAPI = RendererAPI::OpenGL;

    RendererAPI Renderer::GetAPI()
    {
        return s_RendererAPI;
    }
}