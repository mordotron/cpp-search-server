#include "document.h"
using namespace std::string_literals;

std::ostream &operator<<(std::ostream &out, const Document &doc)
{
    out << "{ "s
        << "document_id = "s << doc.id << ", "s
        << "relevance = "s << doc.relevance << ", "s
        << "rating = "s << doc.rating << " }"s;
    return out;
}

