package com.xero.login;

import android.app.*;
import android.content.Intent;
import android.graphics.*;
import android.os.*;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.content.ClipboardManager;
import android.content.Context;
import android.Manifest;
import android.content.pm.PackageManager;
import android.widget.Toast;

import com.orca.xarg.MainActivity;
import com.orca.xarg.Prefs;
import com.orca.xarg.R;
import android.widget.ImageView;

public class LoginActivity extends Activity {

    static {
        System.loadLibrary("Xero");
    }

    private native String Tele();

    private final String USER = "USER";
    private final String PASS = "PASS";
    private Prefs prefs;

    private void setLightStatusBar(Activity activity) {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            activity.getWindow().setStatusBarColor(Color.parseColor("#FF121212"));
            activity.getWindow().setNavigationBarColor(Color.parseColor("#FF121212"));
        }
    }
    private void permisson(Activity activity) {
		if (Build.VERSION.SDK_INT >= 23) {
			if (checkSelfPermission(Manifest.permission.READ_EXTERNAL_STORAGE) == PackageManager.PERMISSION_DENIED
				||checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_DENIED) {
				requestPermissions(new String[] {Manifest.permission.READ_EXTERNAL_STORAGE, Manifest.permission.WRITE_EXTERNAL_STORAGE}, 1000);
			} else {
				//initializeLogic();
			}
		} else {
			//initializeLogic();
		}
	}


    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == 1000) {
            //initializeLogic();
        }}
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        permisson(this);
        setLightStatusBar(this);
        setContentView(R.layout.activity_login);
//        if (!SplashActivity.splashloaded) {
//            finish();
//        }
        prefs = Prefs.with(this);
        final Context m_Context = (Context) this;
        final TextView textUsername = findViewById(R.id.edittext2);
        textUsername.setText(prefs.read(USER, ""));

		ImageView Paste = findViewById(R.id.paste);
        Paste.setOnClickListener(new View.OnClickListener(){
				public void onClick(View v){
            ClipboardManager clipboard = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
            String ed = clipboard.getText().toString();
            if (ed.length() > 19 & !ed.equals("")) {
                textUsername.setText(ed.substring(0, 20));
            } else {
                Toast.makeText(LoginActivity.this, "Invalid Key", Toast.LENGTH_LONG).show();
            }
			}
        });

        Button btnSignIn = findViewById(R.id.button1);
        btnSignIn.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    TextView textUsername = findViewById(R.id.edittext2);


                    if (!textUsername.getText().toString().isEmpty())
                        prefs.write(USER, textUsername.getText().toString());


					String userKey = textUsername.getText().toString();
					Login(m_Context, userKey);

                    if (textUsername.getText().toString().isEmpty())
                        textUsername.setError("Please enter Key");
                    if (textUsername.getText().toString().isEmpty()) {
                        textUsername.setError("Please enter Key");
                    }
				}

            });


    }
    private static void Login(final Context m_Context, final String userKey) {
        Toast.makeText(m_Context,"Checking Key...".toString(),1).show();

        final Handler loginHandler = new Handler() {
            @Override
            public void handleMessage(Message msg) {
                if (msg.what == 0) {
                    Toast.makeText(m_Context,"Successfully".toString(),1).show();
                    Intent i = new Intent(m_Context.getApplicationContext(), MainActivity.class);
                    m_Context.startActivity(i);
                } else if (msg.what == 1) {
                    Toast.makeText(m_Context,"Invalid Key".toString(),1).show();
                }

            }
        };

        new Thread(new Runnable() {
            @Override
            public void run() {
                String result = JatinPAPA(m_Context, userKey);
                if (result.equals("OK")) {
                    loginHandler.sendEmptyMessage(0);
                } else {
                    Message msg = new Message();
                    msg.what = 1;
                    msg.obj = result;
                    loginHandler.sendMessage(msg);
                }
            }
        }).start();
    }


    private static native String JatinPAPA(Context mContext, String userKey);
}

