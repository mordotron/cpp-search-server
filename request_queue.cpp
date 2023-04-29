using namespace std ;
#include "request_queue.h"

    vector<Document> RequestQueue::AddFindRequest(const string& raw_query, DocumentStatus status)
    {
        QueryResult r ;
        r.result_ = search_server_.FindTopDocuments (raw_query, status);
        requests_.push_back (r ) ;
        RemoveOldRequests () ;
        return r.result_ ;
    }

    vector<Document> RequestQueue::AddFindRequest(const string& raw_query)
    {
        QueryResult r ;
        r.result_ = search_server_.FindTopDocuments (raw_query)  ;
        requests_.push_back (r ) ;
        RemoveOldRequests () ;
        return r.result_ ;
    }


    int RequestQueue::GetNoResultRequests() const
    {
        int empty_requests_ = 0 ;

        for ( auto res  : requests_)
        {
            if ( res.result_.empty() ) empty_requests_++ ;
        }

        return empty_requests_ ;// напишите реализацию
    }

   void RequestQueue::RemoveOldRequests ()
   {
       while ( requests_.size() > min_in_day_ )
       {
           requests_.pop_front() ;
       }
   }





