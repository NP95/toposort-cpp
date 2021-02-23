#include <iostream>
#include <toposort.hpp>

int main()
{
  // Declare that our graph nodes hold chars as data.
  toposort::graph<char> g;

  // Create a bunch of nodes.
  auto a = g.create_node('a');
  auto b = g.create_node('b');
  auto c = g.create_node('c');
  auto d = g.create_node('d');
  auto e = g.create_node('e');

  // Add dependencies between the nodes.
  b->depends_on(a);
  b->depends_on(c);
  d->depends_on(b);
  e->depends_on(c);

  // Sort and get the results.
  const auto result = g.sort();

  // Get the results.
  if (result)
  {
    // Print the sorted node list.
    std::cout << "Sorting successul! Order: ";

    for (const auto& n : result.sorted_nodes)
    {
      std::cout << n->data();

      if (n != result.sorted_nodes.back())
        std::cout << ", ";
    }

    return 0;
  }
  else
  {
    // Show which nodes have a cyclic dependency.
    std::cout << "Failed to sort! Cyclic dependency between "
              << result.cyclic_a->data() << " and " << result.cyclic_b->data()
              << std::endl;

    return 1;
  }
}