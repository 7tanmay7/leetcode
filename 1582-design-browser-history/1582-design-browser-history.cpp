class BrowserHistory {
public:
    struct Node {
        string data;
        Node* next;
        Node* back;
        Node(string x) : data(x), next(nullptr), back(nullptr) {}
    };

    Node* currentPage;

    BrowserHistory(string homepage) {
        currentPage = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);
        currentPage->next = newNode;
        newNode->back = currentPage;
        currentPage = newNode;
    }

    string back(int steps) {
        while (steps > 0 && currentPage->back != nullptr) {
            currentPage = currentPage->back;
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps) {
        while (steps > 0 && currentPage->next != nullptr) {
            currentPage = currentPage->next;
            steps--;
        }
        return currentPage->data;
    }
};
