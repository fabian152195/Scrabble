package com.tec.salsas.sendsms;

import android.Manifest;
import android.app.Activity;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.telephony.SmsManager;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity2 extends Activity {

    private final static int SEND_SMS_PERMISSION_REQUEST_CODE = 111;
    private Button sendMessage;

    IntentFilter intentFilter;

    private BroadcastReceiver intentReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            TextView inTxt = (TextView) findViewById(R.id.textMsg);
            inTxt.setText(intent.getExtras().getString("message"));
        }
    };

    protected void onCreate(Bundle savedInstancesState){
        super.onCreate(savedInstancesState);
        intentFilter = new IntentFilter();
        intentFilter.addAction("SMS_RECEIVED_ACTION");
        setContentView(R.layout.activity_main2);
        sendMessage = (Button) findViewById(R.id.send_message);
        final EditText phone = (EditText) findViewById(R.id.phone_no);
        final EditText message = (EditText) findViewById(R.id.message);
        sendMessage.setEnabled(false);

        if(checkPermission(Manifest.permission.SEND_SMS)){
            sendMessage.setEnabled(true);
        }else{
            ActivityCompat.requestPermissions(this, new String[] {Manifest.permission.SEND_SMS}, SEND_SMS_PERMISSION_REQUEST_CODE);
        }
        sendMessage.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String msg = message.getText().toString();
                String phoneNumber = phone.getText().toString();

                if(!TextUtils.isEmpty(msg) && !TextUtils.isEmpty(phoneNumber)){
                    if(checkPermission(Manifest.permission.SEND_SMS)){
                        SmsManager smsManager = SmsManager.getDefault();
                        smsManager.sendTextMessage(phoneNumber, null, msg, null, null);
                    } else{
                        Toast.makeText(MainActivity2.this, "Permission denied", Toast.LENGTH_SHORT).show();
                    }
                }  else{
                    Toast.makeText(MainActivity2.this, "Ingrese un mensaje y un numero de telefono", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private boolean checkPermission(String permission){
        int checkPermission = ContextCompat.checkSelfPermission(this, permission);
        return checkPermission == PackageManager.PERMISSION_GRANTED;
    }

    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults){
        switch (requestCode){
            case SEND_SMS_PERMISSION_REQUEST_CODE:
                if(grantResults.length > 0 && (grantResults[0] == PackageManager.PERMISSION_GRANTED)){
                    sendMessage.setEnabled(true);
                }


                break;

        }
    }

    @Override
    protected void onResume(){
        registerReceiver(intentReceiver, intentFilter);
        super.onResume();
    }

    @Override
    protected void onPause(){
        unregisterReceiver(intentReceiver);
        super.onPause();
    }

}

