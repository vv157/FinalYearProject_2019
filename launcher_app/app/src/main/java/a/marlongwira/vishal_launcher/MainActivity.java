package a.marlongwira.vishal_launcher;

import android.annotation.SuppressLint;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.io.IOException;
import java.util.Set;
import java.util.UUID;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    //Inputs declarations
    ImageView direction_1;
    ImageView direction_2;
    ImageView direction_3;
    ImageView direction_4;
    ImageView direction_5;
    ImageView direction_6;
    ImageView direction_7;
    ImageView direction_8;
    ImageView direction_9;
    Button stop_btn;
    Button start_btn;
//    Button slow_btn;
//    Button fast_btn;
//    Button random_btn;
    Button fire_btn;

    TextView t1;
    String address = null , name=null;

    BluetoothAdapter myBluetooth = null;
    BluetoothSocket btSocket = null;
    Set<BluetoothDevice> pairedDevices;
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        try {setw();} catch (Exception e) {}

    }
    @SuppressLint("ClickableViewAccessibility")
    private void setw() throws IOException
    {
        t1=(TextView)findViewById(R.id.info);
        bluetooth_connect_device();


        start_btn=(Button) findViewById(R.id.start_button);
        stop_btn = (Button) findViewById(R.id.stop_button);
//        slow_btn =(Button) findViewById(R.id.slow_button);
//        fast_btn = (Button) findViewById(R.id.fast_button);
//        random_btn = (Button) findViewById(R.id.random_button);
        fire_btn = (Button) findViewById(R.id.fire_button);
        direction_1 = (ImageView) findViewById(R.id.imageView);
        direction_2 = (ImageView) findViewById(R.id.imageView4);
        direction_3 = (ImageView) findViewById(R.id.imageView6);
        direction_4 = (ImageView) findViewById(R.id.imageView8);
        direction_5 = (ImageView) findViewById(R.id.imageView7);
        direction_6 = (ImageView) findViewById(R.id.imageView3);
        direction_7 = (ImageView) findViewById(R.id.imageView9);
        direction_8 = (ImageView) findViewById(R.id.imageView10);
        direction_9 = (ImageView) findViewById(R.id.imageView2);


//
        start_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                send_message("s");
                start_btn.setBackgroundColor(getResources().getColor(R.color.green_on));
                stop_btn.setBackgroundColor(android.R.drawable.btn_default);
//                slow_btn.setBackgroundColor(android.R.drawable.btn_default);
//                fast_btn.setBackgroundColor(android.R.drawable.btn_default);
                fire_btn.setBackgroundColor(android.R.drawable.btn_default);
                Toast.makeText(getApplicationContext(),"Start button Pressed", Toast.LENGTH_SHORT).show();

            }
        });

        stop_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("t");
                start_btn.setBackgroundColor(android.R.drawable.btn_default);
                stop_btn.setBackgroundColor(getResources().getColor(R.color.green_on));
//                slow_btn.setBackgroundColor(android.R.drawable.btn_default);
//                fast_btn.setBackgroundColor(android.R.drawable.btn_default);
                fire_btn.setBackgroundColor(android.R.drawable.btn_default);
                Toast.makeText(getApplicationContext(),"Stop button Pressed", Toast.LENGTH_SHORT).show();

            }
        });

//        slow_btn.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                send_message("l");
//                Toast.makeText(getApplicationContext(),"Slow button Pressed", Toast.LENGTH_SHORT).show();
//
//            }
//        });
//
//        fast_btn.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                send_message("f");
//                Toast.makeText(getApplicationContext(),"fast button Pressed", Toast.LENGTH_SHORT).show();
//
//            }
//        });

//        random_btn.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                send_message("r");
//                Toast.makeText(MainActivity.this, "Random button Pressed", Toast.LENGTH_SHORT).show();
//            }
//        });
        fire_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("f");
                start_btn.setBackgroundColor(android.R.drawable.btn_default);
                stop_btn.setBackgroundColor(android.R.drawable.btn_default);
//                slow_btn.setBackgroundColor(android.R.drawable.btn_default);
//                fast_btn.setBackgroundColor(android.R.drawable.btn_default);
                fire_btn.setBackgroundColor(getResources().getColor(R.color.green_on));
                Toast.makeText(MainActivity.this, "Fire button Pressed", Toast.LENGTH_SHORT).show();
            }
        });

        direction_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("1");
                Toast.makeText(MainActivity.this, "Position 1 Pressed", Toast.LENGTH_SHORT).show();
            }
        });


        direction_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("2");
                Toast.makeText(MainActivity.this, "Position 2 Pressed", Toast.LENGTH_SHORT).show();
            }
        });
        direction_3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("3");
                Toast.makeText(MainActivity.this, "Position 3 Pressed", Toast.LENGTH_SHORT).show();
            }
        });
        direction_4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("4");
                Toast.makeText(MainActivity.this, "Position 4 Pressed", Toast.LENGTH_SHORT).show();
            }
        });
        direction_5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("5");
                Toast.makeText(MainActivity.this, "Position 5 Pressed", Toast.LENGTH_SHORT).show();
            }
        });
        direction_6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("6");
                Toast.makeText(MainActivity.this, "Position 6 Pressed", Toast.LENGTH_SHORT).show();
            }
        });
        direction_7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("7");
                Toast.makeText(MainActivity.this, "Position 7 Pressed", Toast.LENGTH_SHORT).show();
            }
        });
        direction_8.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("8");
                Toast.makeText(MainActivity.this, "Position 8 Pressed", Toast.LENGTH_SHORT).show();
            }
        });
        direction_9.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                send_message("9");
                Toast.makeText(MainActivity.this, "Position 9 Pressed", Toast.LENGTH_SHORT).show();
            }
        });
//
//        slow_btn.setOnTouchListener(new View.OnTouchListener()
//        {   @Override
//        public boolean onTouch(View v, MotionEvent event){
//            if(event.getAction() == MotionEvent.ACTION_DOWN) {send_message("s");}
//            if(event.getAction() == MotionEvent.ACTION_UP){send_message("0");}
//            return true;}
//        });

    }



    private void bluetooth_connect_device() throws IOException
    {
        try
        {
            myBluetooth = BluetoothAdapter.getDefaultAdapter();
            address = myBluetooth.getAddress();
            pairedDevices = myBluetooth.getBondedDevices();
            if (pairedDevices.size()>0)
            {
                for(BluetoothDevice bt : pairedDevices)
                {
                    address=bt.getAddress().toString();name = bt.getName().toString();
                    Toast.makeText(getApplicationContext(),"Connected", Toast.LENGTH_SHORT).show();

                }
            }

        }
        catch(Exception we){}
        myBluetooth = BluetoothAdapter.getDefaultAdapter();//get the mobile bluetooth device
        BluetoothDevice device = myBluetooth.getRemoteDevice(address);//connects to the device's address and checks if it's available
        btSocket = device.createInsecureRfcommSocketToServiceRecord(myUUID);//create a RFCOMM (SPP) connection
        btSocket.connect();
        try { t1.setText("Device Name: "+name+"\nDevice Address: "+address); }
        catch(Exception e){}
    }

    @Override
    public void onClick(View v)
    {
        try
        {

        }
        catch (Exception e)
        {
            Toast.makeText(getApplicationContext(),e.getMessage(), Toast.LENGTH_SHORT).show();

        }

    }

    private void send_message(String i)
    {
        try
        {
            if (btSocket!=null)
            {

                btSocket.getOutputStream().write(i.toString().getBytes());
            }

        }
        catch (Exception e)
        {
            Toast.makeText(getApplicationContext(),e.getMessage(), Toast.LENGTH_SHORT).show();

        }

    }
}