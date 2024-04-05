#include <sys/types.h>
#include <pthread.h>
#include <jni.h>
#include <string>
#include "obfuscate.h"
#include "ESP.h"
#include "Hacks.h"
#include "StrEnc.h"
#include "Tools.h"
#include "JatinGamer.h"
#include "json.hpp"
#include "Includes.h"
using json = nlohmann::ordered_json;

ESP espOverlay;
int type=1,utype=2;
extern "C" JNIEXPORT void JNICALL
Java_com_orca_xarg_Overlay_DrawOn(JNIEnv *env, jclass , jobject espView, jobject canvas) {
    espOverlay = ESP(env, espView, canvas);
    if (espOverlay.isValid()){
        DrawESP(espOverlay, espOverlay.getWidth(), espOverlay.getHeight());
    }
}
extern "C" JNIEXPORT void JNICALL
Java_com_orca_xarg_Overlay_Close(JNIEnv *,  jobject ) {
   Close();
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_xero_login_LoginActivity_Telegram(JNIEnv *env, jobject thiz ) {
    return env->NewStringUTF("https://t.me/+CcuCYokTSZdkNzAy");
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_xero_login_LoginActivity_MainAct(JNIEnv *env, jobject thiz ) {
    return env->NewStringUTF("com.xero.login.LoginActivity");
}
int expiredDate;
extern "C" JNIEXPORT void JNICALL
Java_com_orca_xarg_FloatLogo_SettingValue(JNIEnv *,  jobject ,jint code,jboolean jboolean1) {
    switch((int)code){
        case 1:
            isPlayerBox = jboolean1;  break;
        case 2:
            isPlayerLine = jboolean1;  break;
        case 3:
            isPlayerDist = jboolean1;  break;
        case 4:
            isPlayerHealth = jboolean1;  break;
        case 5:
            isPlayerName = jboolean1;  break;
        case 6:
            isPlayerHead = jboolean1;  break;
        case 7:
            isr360Alert = jboolean1;  break;
        case 8:
            isSkelton = jboolean1;  break;
        case 9:
            isGrenadeWarning = jboolean1;  break;
        case 10:
            isEnemyWeapon=jboolean1;  break;
        case 11:
			isTeamID = jboolean1; break;
            
        case 13:
            if(jboolean1 != 0)
                options.openState=0;
            else
                options.openState=-1;
            break;
        case 14:
            options.pour=jboolean1;
            break;
        case 15:
            options.tracingStatus=jboolean1;
            break;
        case 28:
            options.iBot=jboolean1;
            break;
            
        case 35:
		        request.memory.LessRecoil = jboolean1;
		    break;
	    case 36:
		        request.memory.SmallCrosshair = jboolean1;
		    break;
	    case 37:
		        request.memory.WideView = jboolean1;
		    break;


    }
}
extern "C"
JNIEXPORT void JNICALL
Java_com_orca_xarg_Toggle_AimKontol(JNIEnv *env, jobject thiz, jint setting_code,
                                              jboolean value) {
    switch((int)setting_code){
        case 13:
            if(value != 0)
                options.openState=0;
            else
                options.openState=-1;
            break;
    }
}



extern "C" JNIEXPORT void JNICALL
Java_com_orca_xarg_FloatLogo_Range(JNIEnv *,  jobject ,jint range) {
    options.aimingRange=1+range;
}

extern "C" JNIEXPORT void JNICALL
Java_com_orca_xarg_FloatLogo_distances(JNIEnv *,  jobject ,jint distances) {
    options.aimingDistance=distances;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_orca_xarg_FloatLogo_recoil(JNIEnv *env, jobject thiz, jint recoil) {
    options.Recoil = recoil;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_orca_xarg_FloatLogo_Bulletspeed(JNIEnv *env, jobject thiz, jint bulletspeed) {
    options.bulletSpeed = bulletspeed;
}

extern "C" JNIEXPORT void JNICALL
Java_com_orca_xarg_FloatLogo_Target(JNIEnv *,  jobject ,jint target) {
    options.aimbotmode=target;
}
extern "C" JNIEXPORT void JNICALL
Java_com_orca_xarg_FloatLogo_AimWhen(JNIEnv *,  jobject ,jint state) {
    options.aimingState=state;
}
extern "C" JNIEXPORT void JNICALL
Java_com_orca_xarg_FloatLogo_AimBy(JNIEnv *,  jobject ,jint aimby) {
    options.priority=aimby;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_orca_xarg_Overlay_getReady(JNIEnv *, jclass ,int typeofgame) {
    int sockCheck=1;
    if (!Create()) {
        perror("Creation failed");
        return false;
    }
    setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&sockCheck, sizeof(int));
    if (!Bind()) {
        perror("Bind failed");
        return false;
    }

    if (!Listen()) {
        perror("Listen failed");
        return false;
    }
    if (Accept()) {
        SetValue sv{};
        sv.mode=typeofgame;
        sv.type=utype;
        send((void*)&sv,sizeof(sv));
       // Close();
        return true;
    }

}

std::string credit;
std::string modname;
std::string token;

jstring native_Check(JNIEnv *env, jclass clazz, jobject mContext, jstring mUserKey) {
    auto userKey = env->GetStringUTFChars(mUserKey, 0);

    std::string hwid = userKey;
    hwid += GetAndroidID(env, mContext);/*https://mod.panelstore.space/connect*/ StrEnc("lakyWbF&oaI*n86C`nK<mwLp*0EeCIO=Zvaw", "\x04\x15\x1F\x09\x24\x58\x69\x09\x02\x0E\x2D\x04\x1E\x59\x58\x26\x0C\x1D\x3F\x53\x1F\x12\x62\x03\x5A\x51\x26\x00\x6C\x2A\x20\x53\x34\x13\x02\x03", 36).c_str();/*https://mod.panelstore.space/connect*/ StrEnc("lakyWbF&oaI*n86C`nK<mwLp*0EeCIO=Zvaw", "\x04\x15\x1F\x09\x24\x58\x69\x09\x02\x0E\x2D\x04\x1E\x59\x58\x26\x0C\x1D\x3F\x53\x1F\x12\x62\x03\x5A\x51\x26\x00\x6C\x2A\x20\x53\x34\x13\x02\x03", 36).c_str();/*https://mod.panelstore.space/connect*/ StrEnc("lakyWbF&oaI*n86C`nK<mwLp*0EeCIO=Zvaw", "\x04\x15\x1F\x09\x24\x58\x69\x09\x02\x0E\x2D\x04\x1E\x59\x58\x26\x0C\x1D\x3F\x53\x1F\x12\x62\x03\x5A\x51\x26\x00\x6C\x2A\x20\x53\x34\x13\x02\x03", 36).c_str();/*https://mod.panelstore.space/connect*/ StrEnc("lakyWbF&oaI*n86C`nK<mwLp*0EeCIO=Zvaw", "\x04\x15\x1F\x09\x24\x58\x69\x09\x02\x0E\x2D\x04\x1E\x59\x58\x26\x0C\x1D\x3F\x53\x1F\x12\x62\x03\x5A\x51\x26\x00\x6C\x2A\x20\x53\x34\x13\x02\x03", 36).c_str();
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);

    std::string UUID = GetUUID(env, hwid.c_str());

    std::string errMsg;

    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;

    
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
		//std::string url = OBFUSCATE("https://api.fyu46.tk/NIKHIL/connect");
       std::string url = OBFUSCATE("https://amnesiapanel.000webhostapp.com/connect");
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, /*POST*/ StrEnc(",IL=", "\x7C\x06\x1F\x69", 4).c_str());
        curl_easy_setopt(curl, CURLOPT_URL,url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, /*https*/ StrEnc("!mLBO", "\x49\x19\x38\x32\x3C", 5).c_str());
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, /*Content-Type: application/x-www-form-urlencoded*/ StrEnc("@;Ls\\(KP4Qrop`b#d3094/r1cf<c<=H)AiiBG6i|Ta66s2[", "\x03\x54\x22\x07\x39\x46\x3F\x7D\x60\x28\x02\x0A\x4A\x40\x03\x53\x14\x5F\x59\x5A\x55\x5B\x1B\x5E\x0D\x49\x44\x4E\x4B\x4A\x3F\x04\x27\x06\x1B\x2F\x6A\x43\x1B\x10\x31\x0F\x55\x59\x17\x57\x3F", 47).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        char data[4096];
        sprintf(data, /*game=PUBG&user_key=%s&serial=%s*/ StrEnc("qu2yXK,YkJyGD@ut0.u~Nb'5(:.:chK", "\x16\x14\x5F\x1C\x65\x1B\x79\x1B\x2C\x6C\x0C\x34\x21\x32\x2A\x1F\x55\x57\x48\x5B\x3D\x44\x54\x50\x5A\x53\x4F\x56\x5E\x4D\x38", 31).c_str(), userKey, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                if (result[/*status*/ StrEnc("(>_LBm", "\x5B\x4A\x3E\x38\x37\x1E", 6).c_str()] == true) {
                    //   std::string token = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*token*/ StrEnc("{>3Lr", "\x0F\x51\x58\x29\x1C", 5).c_str()].get<std::string>();
                    expiredDate = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*rng*/ StrEnc("+n,", "\x59\x00\x4B", 3).c_str()].get<time_t>();
                  //  credit = result["data"]["credit"].get<std::string>();
                    //	modstatus = result["data"]["name2"].get<std::string>();
               //     modname = result["data"]["modname"].get<std::string>();
               //     token = result["data"]["token"].get<std::string>();
                    if (expiredDate + 30 > time(0)) {
                        std::string auth = /*PUBG*/ StrEnc("Q*) ", "\x01\x7F\x6B\x67", 4).c_str();;
                        auth += "-";
                        auth += userKey;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        std::string license = OBFUSCATE("Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E");
                        auth += license.c_str();
                        std::string outputAuth = Tools::CalcMD5(auth);

                        JatinGamer404 = true;

                        if (JatinGamer404) {
                            pthread_t t;
                        }
                    }
                } else {
                    errMsg = result[/*reason*/ StrEnc("LW(3(c", "\x3E\x32\x49\x40\x47\x0D", 6).c_str()].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = "{";
                errMsg += e.what();
                errMsg += "}\n{";
                errMsg += chunk.memory;
                errMsg += "}";
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    return JatinGamer404 ? env->NewStringUTF(/*OK*/ StrEnc("8q", "\x77\x3A", 2).c_str()) : env->NewStringUTF(errMsg.c_str());
}


int Register1(JNIEnv *env) {
    JNINativeMethod methods[] = {{"JatinPAPA", "(Landroid/content/Context;Ljava/lang/String;)Ljava/lang/String;", (void *) native_Check}};

    jclass clazz = env->FindClass("com/xero/login/LoginActivity");
    if (!clazz)
        return -1;

    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return -1;

    return 0;
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (Register1(env) != 0)
        return -1;
    return JNI_VERSION_1_6;
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_junglicheats_ui_LoginActivity_Tele(JNIEnv *env, jobject thiz) {
    // TODO: implement Tele()
}
