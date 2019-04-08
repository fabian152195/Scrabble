package com.example.salsas.sortapp;

import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import serverLogic.*;

public class MainActivity extends AppCompatActivity {

    EditText el;
    Socket listenServer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        el = (EditText)findViewById(R.id.editText);

        Thread myThread = new Thread(new MyServerThread());
        myThread.start();
    }

    class MyServerThread implements Runnable{

        Socket s;
        ServerSocket ss;
        InputStreamReader isr;
        BufferedReader bufferedReader;
        String message;
        Handler h = new Handler();


        @Override
        public void run(){
            try {
                listenServer = new Socket("192.168.100.18",8080);
            } catch (IOException e) {
                e.printStackTrace();
            }
        try{
            //ss = new ServerSocket(8081);
            isr = new InputStreamReader(listenServer.getInputStream());
            bufferedReader = new BufferedReader(isr);
            while(true){

                //s = ss.accept();

                message = bufferedReader.readLine();
                System.out.println("ENTROPO JSBJDSB SDJKBDSJ KBDJS DSJBKDS");
                h.post(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(getApplicationContext(),message,Toast.LENGTH_SHORT).show();
                    }
                });

            }


        }catch (IOException e){
            e.printStackTrace();
        }
        }
    }

    public void send(View v){
        MessageSender messageSender = new MessageSender(listenServer);
        messageSender.execute(el.getText().toString());
    }

}
