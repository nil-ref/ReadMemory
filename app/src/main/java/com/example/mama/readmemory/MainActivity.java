package com.example.mama.readmemory;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(NativeHelper.stringFromJNI());

        this.findViewById(R.id.execute).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                NativeHelper.test();
            }
        });

        this.findViewById(R.id.scan_memory).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startActivity(new Intent(MainActivity.this, ScanMemoryTest.class));
            }
        });
    }


}
