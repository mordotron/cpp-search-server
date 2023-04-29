#pragma once

#include <vector>
#include <stack>

#include "search_server.h"



class RequestQueue {

public:
    explicit RequestQueue(const SearchServer& search_server) : search_server_ (search_server)
    {}

    template <typename DocumentPredicate>
    std::vector<Document> AddFindRequest(const std::string& raw_query, DocumentPredicate document_predicate) ;


    std::vector<Document> AddFindRequest(const std::string& raw_query, DocumentStatus status);

    std::vector<Document> AddFindRequest(const std::string& raw_query) ;

    int GetNoResultRequests() const ;

private:

    const SearchServer& search_server_ ;


    struct QueryResult
    {
        std::vector<Document> result_ ;
    };

    std::deque<QueryResult> requests_;


    const static int min_in_day_ = 1440;


   void RemoveOldRequests () ;
};

template <typename DocumentPredicate>
std::vector<Document> RequestQueue::AddFindRequest(const std::string& raw_query, DocumentPredicate document_predicate)
    {
        // напишите реализацию
         QueryResult r ;
         r.result_ = search_server_.FindTopDocuments (raw_query, document_predicate)  ;
        requests_.push_back (r ) ;

        RemoveOldRequests () ;
        return r.result_ ;

    }
