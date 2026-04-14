#define _CRT_SECURE_NO_WARNINGS

#include "GraphNode.h"

std::vector<std::shared_ptr<GraphNode>> creatGraph()
{
	std::vector<std::shared_ptr<GraphNode>> ret;

	std::shared_ptr<GraphNode> node1 = std::make_shared<GraphNode>(1);
	auto node2 = std::make_shared<GraphNode>(2);
	auto node3 = std::make_shared<GraphNode>(3);

	node1->addEdge(node2);
	node2->addEdge(node3);
	node3->addEdge(node1);

	ret.emplace_back(node1);
	ret.emplace_back(node2);
	ret.emplace_back(node3);

	return ret;
}

int main()
{
	auto graph = creatGraph();
	for (auto& node : graph)
	{
		node->printEdges();
	}

	return 0;
}