package com.orca.xarg;

import android.annotation.SuppressLint;
import android.app.ActivityManager;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.drawable.GradientDrawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.provider.Settings;
import android.support.v4.app.*;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.LinearLayout;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;


public class MainActivity extends AppCompatActivity implements OnClickListener {
    String gameName = "com.tencent.ig";
    static int gameType = 5;

    static {
        System.loadLibrary("Xero");
    }

    private boolean isDisplay = false, isMenuDis = false;
    Context ctx;
    public static String socket;
    public String daemonPath, daemonPath64;
    static boolean isRoot = false, isNoRoot = false, rootMod = false, is32 = false, is64 = false, bitMod = false, verMod = true, isDaemon = false;
    public LinearLayout button1, button2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        CheckFloatViewPermission();
        ctx = this;
        button1 = (LinearLayout) findViewById(R.id.button1);
        button2 = (LinearLayout) findViewById(R.id.button2);
        button1.setOnClickListener(this);
        button2.setOnClickListener(this);
        RadioGroup deviceinfo = (RadioGroup) findViewById(R.id.radioMod);
        RadioGroup bitversion = (RadioGroup) findViewById(R.id.radioBit);
        final String[] version = {"GLOBAL"};
        final Spinner spin = (Spinner) findViewById(R.id.spinner);
        ArrayAdapter<String> dataAdapter = new ArrayAdapter<>(this, R.layout.spinner_list, version);
        dataAdapter.setDropDownViewResource(R.layout.spinner_list);
        spin.setAdapter(dataAdapter);
        spin.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {

                if (spin.getSelectedItem().toString().equals("GLOBAL")) {
                    gameName = "com.pubg.imobile";
                    gameType = 5;
                } else {
                    gameName = "com.pubg.imobile";
                    gameType = 5;
                }




            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });

        deviceinfo.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @SuppressLint("NonConstantResourceId")
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                switch (checkedId) {
                    case R.id.radiobutton3:
                        isRoot = true;
                        ExecuteElf();
                        isNoRoot = false;
                        rootMod = true;
                        break;
                    case R.id.radiobutton4:
                        isNoRoot = true;
                        isRoot = false;
                        rootMod = true;
                        break;
                }
            }
        });
      RadioGroup deviceinfo1 = (RadioGroup) findViewById(R.id.radioMod);
      deviceinfo1.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
        @Override
        public void onCheckedChanged(RadioGroup group, int checkedId) {
          switch (checkedId) {
            case R.id.radiobutton3:
              isRoot = true;
              ExecuteElf("su -c id");
              ExecuteElf("su -c settings put global block_untrusted_touches 0");
              isNoRoot = false;
              rootMod = true;
              break;

            case R.id.radiobutton4:
              ExecuteElf("settings put global block_untrusted_touches 0");
              isNoRoot = true;
              isRoot = false;
              rootMod = true;
              break;
          }
        }
      });
        bitversion.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @SuppressLint("NonConstantResourceId")
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                switch (checkedId) {
                    case R.id.radiobutton5:
                        is32 = true;
                        is64 = false;
                        bitMod = true;
                        break;
                    case R.id.radiobutton6:
                        is64 = true;
                        is32 = false;
                        bitMod = true;
                        break;
                }
            }
        });
        ExecuteElf();
        loadAssets();
        loadAssets64();
        socket = daemonPath;
    }

    @SuppressLint("NonConstantResourceId")
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.button1:
                if (!isDisplay && !isMenuDis) {
                    if (!rootMod || !verMod || !bitMod) {
                        Toast.makeText(MainActivity.this, "Please Select Settings First !!", Toast.LENGTH_LONG).show();
                    } else {
                        if (isNoRoot) {
                            if (is32) {
                                socket = daemonPath;
                            } else if (is64) {
                                socket = daemonPath64;
                            }
                        }
                        if (isRoot) {
                            if (is32) {
                                socket = "su -c " + daemonPath;
                            } else if (is64) {
                                socket = "su -c " + daemonPath64;
                            }
                        }
                        startPatcher();
                  //    startService(new Intent(this, Overlay.class));
                        isDisplay = true;
                        isDaemon = true;
                    }
                } else {
                    Toast.makeText(MainActivity.this, "Already Started !!", Toast.LENGTH_LONG).show();
                }
                break;
            case R.id.button2:
                if (isDisplay) {
                    isDisplay = false;
                    isMenuDis = false;
                    isDaemon = false;
                    stopService(new Intent(this, FloatLogo.class));
                    stopService(new Intent(this, Overlay.class));
                }
                break;
        }
    }

    public void CheckFloatViewPermission() {
        if (!Settings.canDrawOverlays(this)) {
            Toast.makeText(this, "Enable Floating Permission ", Toast.LENGTH_LONG).show();
            startActivityForResult(new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION, Uri.parse("package:" + getPackageName())), 0);
        }
    }

    private boolean isServiceRunning() {
        ActivityManager manager = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
        if (manager != null) {
            for (ActivityManager.RunningServiceInfo service : manager.getRunningServices(Integer.MAX_VALUE)) {
                if (FloatLogo.class.getName().equals(service.service.getClassName())) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean MvAssets(String outPath, String fileName) {
        File file = new File(outPath);
        if (!file.exists()) {
            if (!file.mkdirs()) {
                Log.e("--Method--", "copyAssetsSingleFile: cannot create directory.");
                return false;
            }
        }
        try {
            InputStream inputStream = getAssets().open(fileName);
            File outFile = new File(file, fileName);
            FileOutputStream fileOutputStream = new FileOutputStream(outFile);
            byte[] buffer = new byte[1024];
            int byteRead;
            while (-1 != (byteRead = inputStream.read(buffer))) {
                fileOutputStream.write(buffer, 0, byteRead);
            }
            inputStream.close();
            fileOutputStream.flush();
            fileOutputStream.close();
            return true;
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }

    private void initialization() {
			MvAssets(getFilesDir() + "/", "Xero");
			Handler Handler = new Handler();
			Handler.postDelayed(new Runnable() {
					@Override
					public void run() {}}, 6000);
		}

    void startPatcher() {
        if (!Settings.canDrawOverlays(this)) {
            Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION, Uri.parse("package:" + getPackageName()));
            startActivityForResult(intent, 123);
        } else {
            startFloater();
        }
    }

    private void startFloater() {
        if (!isServiceRunning()) {
            startService(new Intent(this, FloatLogo.class));
        } else {
            Toast.makeText(this, "Service Already Running!", Toast.LENGTH_SHORT).show();
        }
    }

    private void ExecuteElf() {
        try {
            Runtime.getRuntime().exec("su -c", null, null);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void ExecuteElf(String shell) {
		String s=shell;

		try {
			Runtime.getRuntime().exec(s, null, null);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void RunCPP(String path) {
		try {
			ExecuteElf("chmod 777 " + getFilesDir() + path);
			ExecuteElf(getFilesDir() + path);
			ExecuteElf("su -c chmod 777 " + getFilesDir() + path);
			ExecuteElf("su -c " + getFilesDir() + path);
		} catch (Exception e) {
		}
	}


    public void loadAssets() {
        String filesDir = getFilesDir().toString() + "/sock";
        try {
            OutputStream myOutput = new FileOutputStream(filesDir);
            byte[] buffer = new byte[1024];
            int length;
            InputStream myInput = getAssets().open("sock");
            while ((length = myInput.read(buffer)) > 0) {
                myOutput.write(buffer, 0, length);
            }
            myInput.close();
            myOutput.flush();
            myOutput.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        daemonPath = getFilesDir().toString() + "/sock";
        try {
            Runtime.getRuntime().exec("chmod 777 " + daemonPath);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void loadAssets64() {
        String filesDir = getFilesDir().toString() + "/sock64";
        try {
            OutputStream myOutput = new FileOutputStream(filesDir);
            byte[] buffer = new byte[1024];
            int length;
            InputStream myInput = getAssets().open("sock64");
            while ((length = myInput.read(buffer)) > 0) {
                myOutput.write(buffer, 0, length);
            }
            myInput.close();
            myOutput.flush();
            myOutput.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        daemonPath64 = getFilesDir().toString() + "/sock64";
        try {
            Runtime.getRuntime().exec("chmod 777 " + daemonPath64);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
