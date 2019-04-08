package com.example.salsas.sortapp;

import android.os.AsyncTask;
import android.provider.ContactsContract;

import java.io.DataOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.SocketAddress;

public class MessageSender extends AsyncTask<String,Void,Void>
{

    Socket s;
    DataOutputStream dos;
    PrintWriter pw;

    MessageSender(Socket s){
        this.s = s;
    }

    @Override
    protected Void doInBackground(String... voids) {

        String message = voids[0];

        try{
            pw = new PrintWriter(s.getOutputStream());
            pw.write(message);
            pw.flush();
            //pw.close();
            //s.close();

        }catch (IOException e){
            e.printStackTrace();
        }


        return null;
    }
}
