package com.xero.login;

import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.widget.Button;
import java.util.HashMap;
import jokhio.downloader.DownloadService;
import java.util.TimerTask;
import android.animation.ObjectAnimator;
import java.util.Timer;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.Window;
import android.content.ServiceConnection;
import android.content.ComponentName;
import android.view.animation.BounceInterpolator;
import java.io.File;
import android.content.Intent;
import android.content.Context;
import android.os.IBinder;
import android.view.View.OnClickListener;
import android.view.View;
import android.widget.Toast;
import java.nio.file.*;
import android.widget.TextView;
import android.widget.Toast;
import com.orca.xarg.MainActivity;
import com.orca.xarg.Prefs;
import com.orca.xarg.R;

public class DownloaderActivity extends Activity {
    Button btn;

    private double state = 0;
	private native String link();
    private  DownloadService downloadService;
    private HashMap<String, Object> map = new HashMap<>();
    private Intent i = new Intent();
    private TimerTask t;
	private Timer _timer = new Timer();
    String url = "https://github.com/clevex/bappppppps/raw/c8c508b9803e440cd1a55fc6000760df04055a48/Bypass"; //Enter Your CPP Link Here
	String name= "Bypass"; //Enter CPP Name Here That You Use In Your FloatingActivity.java

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_download);
        Intent intent = new Intent(this, DownloadService.class);
                bindService(intent, conn, Context.BIND_AUTO_CREATE);


        btn = findViewById(R.id.btn);
        btn.setOnClickListener(new View.OnClickListener(){

            public void onClick(View v){
                if (downloadService != null) {

				File file = new File(getFilesDir()+"/"+name);

                    if (file.exists()) {
                        file.delete();
                    }

                   downloadService.startDownload(url, name, getFilesDir()+"/");
                    _progr();

					Toast.makeText(getApplicationContext(),"BYPASS DOWNLOADING FROM SERVER", Toast.LENGTH_SHORT).show();


                }

                else {

                    }
            }
        });
    }
    ServiceConnection conn = new ServiceConnection() {
        @Override
     public void onServiceDisconnected(ComponentName name) {

        }

        @Override
        public void onServiceConnected( ComponentName name, IBinder service) {
            //RETURN AN MsgService object
            downloadService = ((DownloadService.MsgBinder) service). getService();
        }

	};
	    public void _progr() {
        t = new TimerTask() {
            @Override
            public void run() {
                runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            map = new HashMap<>();
                            map = downloadService.getStats();
                            state = Double.parseDouble(map.get((new Object() {
                                                                   int t;
                                                                   public String toString() {
                                                                       byte[] buf = new byte[5];
                                                                       t = -1532005521;
                                                                       buf[0] = (byte) (t >>> 8);
                                                                       t = 398067822;
                                                                       buf[1] = (byte) (t >>> 15);
                                                                       t = -2060415210;
                                                                       buf[2] = (byte) (t >>> 15);
                                                                       t = -951454790;
                                                                       buf[3] = (byte) (t >>> 20);
                                                                       t = 1709240884;
                                                                       buf[4] = (byte) (t >>> 24);
                                                                       return new String(buf);
                                                                   }
                                                               }.toString())).toString());
                            if (state == 1) {
						Toast.makeText(getApplicationContext(),"LOADING BYPASS...", Toast.LENGTH_SHORT).show();
							 // downloading

                            }
                            else {
                                if (state == 2) {
						            i.setClass(getApplicationContext(), MainActivity.class);
                                    startActivity(i);

                                    Path path = null;
                                    if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.O) {
                                        path = Paths.get(getFilesDir() + "/",name);
                                    }
                                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                                        if (Files.exists(path)) {
                                            // FILE EXIST SO THIS TOAST WILL WORK
                                            Toast.makeText(getApplicationContext(),"BYPASS LOAD FAILED", Toast.LENGTH_SHORT).show();
                                            finish();
                                            t.cancel();
                                        }
                                    }

                                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
                                        if (Files.notExists(path)) {

                                            Toast.makeText(getApplicationContext(),"BYPASS LOADED", Toast.LENGTH_SHORT).show();
                                            t.cancel();
                                        }
                                    }
                                }
                                else {
                                    if (state == 3) {
                                        Toast.makeText(getApplicationContext(),"FAILED TO LOAD", Toast.LENGTH_SHORT).show();
                                        t.cancel();
                                  }
                                    else {
                                        if (state == 4) {
                                            t.cancel();
                                        }
                                        else {
                                            t.cancel();
                                        }
                                    }
                                }
                            }
                        }
                    });
            }
        };
        _timer.scheduleAtFixedRate(t, (int)(0), (int)(500));
	}
    @Override
    protected void onDestroy() {
        super.onDestroy();

        unbindService(conn);
    }

}
