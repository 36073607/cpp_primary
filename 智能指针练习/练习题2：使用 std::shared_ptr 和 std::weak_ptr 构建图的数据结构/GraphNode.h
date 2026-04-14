#pragma once

#ifndef _GraphNode_
#define _GraphNode_

#include <vector>
#include <memory>
#include <iostream>


class GraphNode
{
private:
	int _id;
	std::vector<std::weak_ptr<GraphNode>> _vec;

public:
	GraphNode(int id);
	void addEdge(const std::shared_ptr<GraphNode>& node);
	void printEdges() const;
};


#endif // ! _GraphNode_
