#ifndef CELL_RENDERER_COMMAND_BUFFER_H
#define CELL_RENDERER_COMMAND_BUFFER_H

#include <vector>

#include <math/linear_algebra/matrix.h>

#include "render_command.h"

namespace Cell
{
    class Mesh;
    class Material;

    /* NOTE(Joey):

      Command buffer.

      Can all be done in a renderer, but merely added via
      composition to keep things organized.

    */
    class CommandBuffer
    {
    public:

    private:
        std::vector<RenderCommand> m_RenderCommands;

    public:
        CommandBuffer();
        ~CommandBuffer(); 
        
        // NOTE(Joey): pushes render state relevant to a single render call
        // to the command buffer.
        void Push(Mesh *mesh, Material *material, math::mat4 transform);

        // NOTE(Joey): clears the command buffer; usually done after issuing
        // all the stored render commands.
        void Clear();
        // NOTE(Joey): sorts the command buffer; first by shader, then by 
        // texture bind.
        void Sort();

        // NOTE(Joey): returns the list of render commands. For minimizing
        // state changes it is advised to first call Sort() before retrieving
        // and issuing the render commands.
        std::vector<RenderCommand> GetRenderCommands();
    };
}

#endif