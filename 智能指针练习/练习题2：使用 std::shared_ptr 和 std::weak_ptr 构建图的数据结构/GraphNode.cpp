#define _CRT_SECURE_NO_WARNINGS

#include "GraphNode.h"

GraphNode::GraphNode(int id) : _id(id) {}

void GraphNode::addEdge(const std::shared_ptr<GraphNode>& node)
{
	_vec.push_back(node);
}

void GraphNode::printEdges() const
{
	std::cout << "Node" << _id << " is connected to: ";
	for (auto& node : _vec)
	{
		auto locked = node.lock();//»ñÈ¡shared_ptr
		std::cout << locked->_id << " ";
	}
	std::cout << std::endl;
}

