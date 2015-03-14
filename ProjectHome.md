Dependency Graph

Build a dependency graph for the rules and queries in the Datalog program.

Make a node in the graph for each query and each rule in the Datalog program. Don't add the same node to the graph more than once.

Assign an identifier to each node in the graph. If the node is a query node, the identifier is Qn where n is the number of the query in the list of queries given in the Datalog program. For example, the first query has identifer Q1, the second query has identifer Q2, etc. If the node is a rule node, the identifier is Rn where n is the number of the rule in the list of rules given in the input. For example, the first rule has identifer `R1`, the second rule has identifer `R2`, etc.

Make an edge in the graph for each dependency in the Datalog program. Add an edge to the graph from node x to node y if the evaluation of x depends on the result of y. Don't add the same edge to the graph more than once.

A query depends on a rule if the predicate name of the query is the same as the predicate name of the head of the rule. A rule depends on another rule if any of the predicate names in the body of the first rule is the same as the predicate name of the head of the second rule.

Note that more than one rule may have the same predicate name in the head. This means that a single query may depend on more than one rule and a single name in the body of a rule may depend on more than one rule.

Note that a rule may depend on itself.

Note that queries may depend on rules and rules may depend on other rules. However, rules never depend on queries and queries never depend on other queries.
Graph Output

Output a line with the title 'Dependency Graph' followed by the dependency graph followed by a blank line. Print the graph using an adjacency list representation. Output each node in the graph on a separate line. For each node x, print two spaces followed by the identifier for x followed by a colon and a space separated list of the identifiers for each node y such that there is an edge from node x to node y. Sort each list of successor nodes by identifier. Sort the output lines by node identifier.
Query Output

For each query in the Datalog program:

> Output the query (in the same form as in a Datalog program) followed by a blank line.
> Run a depth-first search on the dependency graph starting with the node that represents the query.
> Output the postorder numbers for the nodes that are reachable from the query followed by a blank line.
> Output the rules the query depends on (listed in the order they should be evaluated) followed by a blank line.
> Output the backward edges followed by a blank line.

Depth-First Search (Postorder Numbers)

For each query in the Datalog program, run a depth-first search on the dependency graph starting with the node that represents the query. Assign postorder numbers to each node visited in the search starting with a postorder number of 1. When there is a choice of which node to visit next, choose the node identifier that comes first alphabetically.

Output a line with the title 'Postorder Numbers' indented by two spaces, followed by the postorder numbers for the nodes that are reachable from the query, followed by a blank line. Output each node on a separate line. For each node (reachable from the query), output the node identifier indented by four spaces and followed by a colon, a space, and the postorder number assigned to the node. Sort the output lines by node identifier. Don't output nodes that are not reachable from the query.
Topological Sort (Rule Evaluation Order)

Sort the nodes that are reachable from the query by increasing postorder number.

Output a line with the title 'Rule Evaluation Order' indented by two spaces, followed by the identifiers for the rules that are reachable from the query (sorted by increasing postorder number), followed by a blank line. (Don't output the identifier for the query node.) Output each node on a separate line. For each line, output the node identifier indented by four spaces. Don't output nodes that are not reachable from the query.
Cycle Finding (Backward Edges)

Run the cycle finding algorithm on the nodes that are reachable from the query. A graph has a cycle if it has a backward edge. An edge (x->y) is a backward edge if the postorder number at the tail of the edge (node x) is less than or equal to the postorder number at the head of the edge (node y). Identify the nodes that are reachable from the query and have one or more backward edges leaving the node.

Output a line with the title 'Backward Edges' indented by two spaces, followed by the backward edges, followed by a blank line. Output each node with backward edges on a separate line. For each node x (with backward edges), output four spaces followed by the identifier for x, followed by a colon and a space separated list of the identifiers for each node y such that there is a backward edge from node x to node y. Sort each list of backward edges by identifier. Sort the lines by node identifier. Don't output nodes that are not reachable from the query. Don't output nodes that don't have backward edges.
Implementation Requirements

> Don't create duplicate nodes or duplicate edges in the graph.
> Print node identifiers in alphabetic order (except when printing the evaluation order for the rules).
> When there is a choice of which node to visit next in the depth-first search, choose the node identifier that comes first alphabetically.

Implementation Suggestions

> Use a map from a string to a node to store the graph. (The string is the node identifier for the node.)
> Each node in the graph contains a set of strings, a visited flag, and a postorder number. (The set of strings contains the identifiers of the successor nodes.)