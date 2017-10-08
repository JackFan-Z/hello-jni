package com.example.jackfan.hellojniold;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    final String TAG = MainActivity.class.getSimpleName();
    TextView textView;
    int count = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = (TextView) findViewById(R.id.textViewJni);
        textView.setText(stringFromJNI() + " - " + count);
        Button button = (Button) findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                count++;
                textView.setText(stringFromJNI() + " - " + count);
            }
        });

        int testResult = runTest(101, 2000, new String("I\'m Jack"));
        Log.d(TAG, "testResult " + testResult);
    }

    public native String stringFromJNI();
    public native int runTest(int parameter1, int parameter2, String paraString);

    static {
        System.loadLibrary("hello-jni");
    }
}
