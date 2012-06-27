/***************************************************************
 * Name:      tconsoleApp.h
 * Purpose:   Defines Application Class
 * Author:    mikhail kostin (kostin.m@softcase.ru)
 * Created:   2012-06-07
 * Copyright: mikhail kostin ()
 * License:
 **************************************************************/

#ifndef TCONSOLEAPP_H
#define TCONSOLEAPP_H

#include <wx/app.h>

class tconsoleApp : public wxApp
{
    public:
        virtual bool OnInit();
        wxCriticalSection critsec;

};

#endif // TCONSOLEAPP_H
