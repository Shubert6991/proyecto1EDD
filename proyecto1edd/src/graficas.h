#include <graphviz/gvc.h>

bool DotGraphGenerator::saveImage()
{
  std::string o_arg = std::string("-o") + "/path/to/image_file.png";
  char* args[] = {const_cast<char*>("dot"), const_cast<char*>("Tpng"), const_cast<char*>("-Gsize=8,4!"), const_cast<char*>("-Gdpi=100"),
  const_cast<char*>(DOT_TEXT_FILE.c_str()),  //DOT_TEXT_FILE is the file path in which the graph is saved as valid DOT syntax
  const_cast<char*>(o_arg.c_str()) };

  const int argc = sizeof(args)/sizeof(args[0]);
  Agraph_t *g, *prev = NULL;
  GVC_t *gvc;

  gvc = gvContext();
  gvParseArgs(gvc, argc, args);

  while ((g = gvNextInputGraph(gvc)))
  {
    if (prev)
    {
      gvFreeLayout(gvc, prev);
      agclose(prev);
    }
    gvLayoutJobs(gvc, g);
    gvRenderJobs(gvc, g);
    prev = g;
  }

  return !gvFreeContext(gvc);
}
