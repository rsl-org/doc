#include <rsl/doc>

namespace rsl::doc {
void NamedEntity::print(std::string_view path) const {
  std::cout << path << " :" << '\n';
}

std::string NamedEntity::to_json(int indent) const {
  return "{\"type\": \"symbol\", \"kind\": \"\"}";
}

void Namespace::print(std::string_view path) const {
  for (auto&& entity : children) {
    entity->print();
//     //   entity->print(path.empty() ? name : std::string(path) + "::" + name);
  }
}

std::string Namespace::to_json(int indent) const {
  std::string pad(indent, ' ');
  std::string out = pad + "{\n";
  bool first      = true;
  for (auto&& entity : children) {
    if (!first)
      out += ",\n";
    //   out += pad + "  \"" + name + "\": " +
    out += entity->to_json(indent + 2);
    first = false;
  }
  out += "\n" + pad + "}";
  return out;
}

void run(std::unique_ptr<Namespace> ns, int argc, char** argv) {
    ns->print();
}

}