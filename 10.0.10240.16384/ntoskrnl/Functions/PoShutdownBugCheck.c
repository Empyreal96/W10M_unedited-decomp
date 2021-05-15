// PoShutdownBugCheck 
 
void __fastcall __noreturn PoShutdownBugCheck(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v8; // r4
  int v11; // r0
  unsigned int v12[2]; // [sp+8h] [bp-40h] BYREF
  unsigned int v13; // [sp+10h] [bp-38h] BYREF
  int v14; // [sp+14h] [bp-34h]
  int v15; // [sp+18h] [bp-30h]
  int v16; // [sp+1Ch] [bp-2Ch]
  int v17; // [sp+20h] [bp-28h]
  int v18; // [sp+24h] [bp-24h]
  int v19; // [sp+28h] [bp-20h]
  int v20; // [sp+2Ch] [bp-1Ch]
  int v21; // [sp+30h] [bp-18h]

  v8 = (unsigned __int8)PopCriticalShutdownInProgress;
  __dmb(0xBu);
  if ( v8 )
  {
    v12[0] = -300000000;
    v12[1] = -1;
    KeDelayExecutionThread(0, 0, v12);
  }
  PopInternalAddToDumpFile(0, 0, 0);
  v14 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( !a1 )
  {
    v14 = 0;
    IoConfigureCrashDump(0, 0);
  }
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = PsGetCurrentThreadId();
  v11 = PsGetCurrentThreadProcessId();
  dword_61EC90 = (int)&v13;
  v16 = v11;
  v17 = a2;
  v18 = a3;
  v19 = a4;
  v20 = a5;
  v21 = a6;
  ZwInitiatePowerAction();
  KeBugCheckEx(a2, a3, a4, a5, a6);
}
