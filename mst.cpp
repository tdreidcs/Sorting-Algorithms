#include "mst.hpp"

using std::endl;


ostream &operator<<(ostream &os, const MST &M)
{
  os << "MST: " << M.name << " {\n";
  os << " total weight: " << M.wt << endl;
  os << " edges = {\n";
  for (auto e : M) {
    os << "  " << e << '\n';
  }
  os << " }" << endl;
  os << "}" << endl;

  return os;
}

