// ExpTranslateNtPath 
 
int __fastcall ExpTranslateNtPath(int a1, int a2, int a3, int a4)
{
  int v5; // r5
  unsigned __int16 *v8; // r7
  int v10; // r4
  int *v11; // r2
  int v12; // r3
  int v13; // r0
  int i; // r6
  int v15; // r5
  int *v16; // [sp+10h] [bp-F0h]
  int v17; // [sp+14h] [bp-ECh]
  int v18; // [sp+20h] [bp-E0h] BYREF
  __int16 v19[4]; // [sp+28h] [bp-D8h] BYREF
  int v20; // [sp+38h] [bp-C8h]
  int v21; // [sp+3Ch] [bp-C4h]
  __int16 *v22; // [sp+40h] [bp-C0h]
  int v23; // [sp+44h] [bp-BCh]
  int v24; // [sp+48h] [bp-B8h]
  int v25; // [sp+4Ch] [bp-B4h]
  int v26; // [sp+50h] [bp-B0h] BYREF
  char v27[8]; // [sp+58h] [bp-A8h] BYREF
  char v28[8]; // [sp+60h] [bp-A0h] BYREF
  char v29[24]; // [sp+68h] [bp-98h] BYREF
  char v30; // [sp+80h] [bp-80h] BYREF

  v5 = a1 + 12;
  v18 = 0;
  RtlInitUnicodeString((unsigned int)v19, (unsigned __int16 *)(a1 + 12));
  v8 = (unsigned __int16 *)((unsigned __int16)v19[0] + v5 + 2);
  if ( !wcslen(v8) )
    v8 = 0;
  if ( a2 == 1 )
    return sub_815194();
  v20 = 24;
  v21 = 0;
  v23 = 576;
  v22 = v19;
  v24 = 0;
  v25 = 0;
  v10 = ZwOpenFile();
  if ( v10 >= 0 )
  {
    v17 = 144;
    v16 = &v26;
    v10 = ZwDeviceIoControlFile();
    if ( v10 >= 0 )
    {
      if ( v26 == 1 )
      {
LABEL_8:
        ZwClose();
        if ( v26 == 1 )
        {
          v11 = (int *)&v30;
          v12 = 1;
        }
        else
        {
          v11 = &v18;
          v12 = 0;
        }
        if ( a2 == 4 )
          v13 = ExpCreateOutputEFI(a3, a4, v11, v29, v27, v28, v8, v12, v16, v17);
        else
          v13 = ExpCreateOutputSIGNATURE(a3, a4, v11, v29, v27, v28, v8, v12, v16, v17);
        return v13;
      }
      if ( v26 )
      {
        v10 = -1073741804;
      }
      else
      {
        for ( i = 2352; ; i *= 2 )
        {
          v15 = ExAllocatePoolWithTag(512, i, 1920364101);
          if ( !v15 )
            break;
          v17 = i;
          v16 = (int *)v15;
          v10 = ZwDeviceIoControlFile();
          if ( v10 >= 0 )
          {
            v18 = *(_DWORD *)(v15 + 8);
            ExFreePoolWithTag(v15);
            goto LABEL_8;
          }
          ExFreePoolWithTag(v15);
          if ( v10 != -1073741789 )
            goto LABEL_16;
        }
        v10 = -1073741670;
      }
    }
LABEL_16:
    ZwClose();
  }
  return v10;
}
