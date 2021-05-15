// IoConfigureCrashDump 
 
int __fastcall IoConfigureCrashDump(int a1, int a2)
{
  _BYTE *v4; // r0
  int v5; // r2
  unsigned int v6; // r5
  int v7; // r3
  int v8; // r4
  int v9; // r2
  int v10; // r3
  _BYTE *v11; // r6
  int v12; // r0
  int v13; // r1
  __int16 v14; // r3
  _DWORD v16[2]; // [sp+0h] [bp-68h] BYREF
  unsigned __int16 v17[16]; // [sp+8h] [bp-60h] BYREF
  char v18[32]; // [sp+28h] [bp-40h] BYREF

  qmemcpy(v17, "C:\\pagefile.sys", 30);
  v4 = memset(v18, 0, sizeof(v18));
  if ( !a2 )
    v4 = (_BYTE *)IopReadDumpRegistry((int)v4, 0);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(__int16 *)(v6 + 0x134) - 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !a1 )
  {
    v4 = (_BYTE *)ExAcquireResourceExclusiveLite((int)&IopCrashDumpLock, 1, v5, v7);
    if ( !v4 )
    {
      v8 = -1073741823;
      goto LABEL_16;
    }
    v8 = ((int (*)(void))IopDisableCrashDump)();
    IopRemoveDumpCapsuleSupport();
    goto LABEL_14;
  }
  if ( a1 == 1 )
  {
    v4 = (_BYTE *)MmGetPageFileForCrashDump(v4);
    v11 = v4;
    if ( !v4 )
    {
      v8 = -1073741772;
      goto LABEL_16;
    }
    v12 = ExAcquireResourceExclusiveLite((int)&IopCrashDumpLock, 1, v9, v10);
    v8 = IopDisableCrashDump(v12);
    if ( v8 >= 0 )
    {
      RtlInitUnicodeString((unsigned int)v16, v17);
      v13 = v16[0];
      *(_WORD *)v16[1] = *(_WORD *)dword_63282C;
      if ( IopInitializeCrashDump(v11, v13) )
      {
        IopRemoveDumpCapsuleSupport();
        v8 = 0;
      }
      else
      {
        IopInitDumpCapsuleSupport();
        v8 = -1073741823;
      }
    }
LABEL_14:
    v4 = (_BYTE *)ExpReleaseResourceForThreadLite((int)&IopCrashDumpLock, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    goto LABEL_16;
  }
  v8 = -1073741808;
LABEL_16:
  v14 = *(_WORD *)(v6 + 308) + 1;
  *(_WORD *)(v6 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    KiCheckForKernelApcDelivery((int)v4);
  return v8;
}
