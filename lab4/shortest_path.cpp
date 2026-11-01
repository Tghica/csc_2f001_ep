#include "shortest_path.h"

#include <iostream>
#include <vector>

using namespace std;

shortest_path_t::shortest_path_t(location_t* from, location_t* to)
    : head(nullptr), base(nullptr), from(from), to(to) {
}

shortest_path_t::~shortest_path_t() {
    while (head != nullptr) {
        node_t* next = head->next;
        delete head;
        head = next;
    }
}

void shortest_path_t::compute() {
    while (head != nullptr) {
        node_t* next = head->next;
        delete head;
        head = next;
    }

    base = nullptr;
    head = new node_t{
        nullptr,
        from,
        nullptr,
        0.0,
        from->distance_to(to),
        false
    };

    while (true) {
        base = nullptr;
        for (node_t* current = head; current != nullptr; current = current->next) {
            if (!current->visited &&
                (base == nullptr || current->total < base->total)) {
                base = current;
            }
        }

        if (base == nullptr || base->location == to) {
            return;
        }

        base->visited = true;
        for (location_t** neighbor = base->location->neighbors;
             *neighbor != nullptr;
             ++neighbor) {
            location_t* current_location = *neighbor;
            double from_origin = base->from_origin
                + base->location->distance_to(current_location);
            double total = from_origin + current_location->distance_to(to);

            node_t* current_node = nullptr;
            for (node_t* current = head; current != nullptr; current = current->next) {
                if (current->location == current_location) {
                    current_node = current;
                    break;
                }
            }

            if (current_node == nullptr) {
                current_node = new node_t{
                    head,
                    current_location,
                    base,
                    from_origin,
                    total,
                    false
                };
                head = current_node;
            } else if (from_origin < current_node->from_origin) {
                current_node->from = base;
                current_node->from_origin = from_origin;
                current_node->total = total;
                current_node->visited = false;
            }
        }
    }
}

void shortest_path_t::display() {
    node_t* destination = nullptr;
    for (node_t* current = head; current != nullptr; current = current->next) {
        if (current->location == to) {
            destination = current;
            break;
        }
    }

    if (destination == nullptr) {
        cout << "unable to find a path from " << from->name
             << " to " << to->name << endl;
        return;
    }

    vector<node_t*> path;
    for (node_t* current = destination; current != nullptr; current = current->from) {
        path.push_back(current);
    }

    cout << "path from " << from->name << " to " << to->name << endl;
    for (auto current = path.rbegin(); current != path.rend(); ++current) {
        cout << "  * " << (*current)->location->name
             << " at " << (*current)->from_origin
             << " km from " << from->name << endl;
    }
}