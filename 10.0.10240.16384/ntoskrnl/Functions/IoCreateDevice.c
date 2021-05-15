// IoCreateDevice 
 
int __fastcall IoCreateDevice(int a1, int a2, char *a3, unsigned int a4, int a5, char a6, _DWORD *a7)
{
  int v9; // r6
  int v10; // r5
  BOOL v11; // r8
  int v12; // r0
  int v14; // r3
  int v15; // r3
  unsigned int v16; // r6
  int v17; // r4
  _BYTE *v18; // r1
  __int16 v19; // r2
  _BYTE *v20; // r0
  int v21; // r0
  _BYTE *v22; // r3
  _BYTE *v23; // r3
  unsigned int v24; // r3
  unsigned int v25; // r3
  _BYTE *v26; // [sp+18h] [bp-A0h] BYREF
  unsigned int v27; // [sp+1Ch] [bp-9Ch]
  unsigned int v28; // [sp+20h] [bp-98h]
  int v29; // [sp+24h] [bp-94h]
  char *v30; // [sp+28h] [bp-90h]
  int v31; // [sp+2Ch] [bp-8Ch]
  int v32; // [sp+30h] [bp-88h] BYREF
  int v33; // [sp+34h] [bp-84h]
  int v34[3]; // [sp+38h] [bp-80h] BYREF
  int v35; // [sp+44h] [bp-74h]
  int v36; // [sp+48h] [bp-70h]
  int v37; // [sp+4Ch] [bp-6Ch]
  char v38[8]; // [sp+50h] [bp-68h] BYREF
  unsigned __int16 v39[20]; // [sp+58h] [bp-60h] BYREF

  v9 = a2;
  v10 = a5;
  v29 = 0;
  v30 = a3;
  v33 = a2;
  v26 = 0;
  v28 = 0;
  v31 = a2 + 184;
LABEL_2:
  v27 = 0;
  while ( 1 )
  {
    if ( (v10 & 0x80) != 0 )
    {
      __dmb(0xBu);
      do
      {
        v24 = __ldrex((unsigned int *)&IopUniqueDeviceObjectNumber);
        v25 = v24 + 1;
      }
      while ( __strex(v25, (unsigned int *)&IopUniqueDeviceObjectNumber) );
      __dmb(0xBu);
      RtlStringCchPrintfW(v39, 0x11u, (int)L"\\Device\\%08lx", v25);
      RtlInitUnicodeString((unsigned int)v38, v39);
      a3 = v38;
      v30 = v38;
    }
    v11 = a3 != 0;
    v12 = IopCreateDefaultDeviceSecurityDescriptor(a4, v10);
    if ( a4 == 8 || a4 == 7 )
      goto LABEL_47;
    if ( a4 != 3 )
    {
      if ( a4 != 36 )
        goto LABEL_8;
LABEL_47:
      v29 = 512;
      goto LABEL_8;
    }
    v29 = 2048;
LABEL_8:
    v34[0] = 24;
    v34[1] = 0;
    if ( !IopCaseInsensitive )
      return sub_7EE37C();
    v14 = 576;
    v34[2] = (int)v30;
    v35 = 576;
    v36 = v12;
    v37 = 0;
    if ( a6 )
    {
      v14 = 608;
      v35 = 608;
    }
    if ( v11 )
      v35 = v14 | 0x10;
    v15 = v9 & 7;
    if ( (v9 & 7) != 0 )
      v15 = 8 - (v9 & 7);
    v16 = v9 + v15;
    if ( v16 >= 0xFFFFFF10 )
    {
      v17 = -1073741811;
      goto LABEL_40;
    }
    v17 = ObCreateObject(0, (_DWORD *)IoDeviceObjectType, (int)v34, 0, 0, v16 + 240, 0, 0, &v26);
    if ( v17 < 0 )
      goto LABEL_40;
    memset(v26, 0, v16 + 240);
    v10 = a5;
    v18 = &v26[v16 + 184];
    *((_DWORD *)v18 + 1) = v26;
    *((_DWORD *)v26 + 44) = v18;
    *(_WORD *)v18 = 13;
    *((_WORD *)v18 + 1) = 0;
    *((_DWORD *)v18 + 12) = 0;
    *((_DWORD *)v18 + 2) = 0;
    *((_DWORD *)v18 + 3) = 0;
    *(_WORD *)v26 = 3;
    *((_WORD *)v26 + 1) = v31;
    *((_DWORD *)v26 + 11) = a4;
    *((_DWORD *)v26 + 8) = a5;
    if ( a4 == 7 || a4 == 31 || a4 == 2 || a4 == 36 )
      break;
LABEL_22:
    v19 = v29;
    *((_DWORD *)v26 + 23) = 0;
    *((_WORD *)v26 + 86) = v19;
    *((_DWORD *)v26 + 7) = 128;
    if ( a6 )
      *((_DWORD *)v26 + 7) |= 8u;
    if ( v11 )
      *((_DWORD *)v26 + 7) |= 0x40u;
    v9 = v33;
    if ( v33 )
      *((_DWORD *)v26 + 10) = v26 + 184;
    else
      *((_DWORD *)v26 + 10) = 0;
    v26[48] = 1;
    if ( a4 == 3 || a4 > 7 && (a4 <= 9 || a4 == 20 || a4 == 32) )
    {
      v23 = v26 + 52;
      *((_DWORD *)v26 + 13) = v26 + 52;
      *((_DWORD *)v23 + 1) = v23;
    }
    else
    {
      KeInitializeDeviceQueue((int)(v26 + 96));
    }
    v20 = v26;
    if ( (*((_DWORD *)v26 + 8) & 0x40001) == 0 )
    {
      *(_DWORD *)(*((_DWORD *)v26 + 44) + 16) |= 0x800u;
      v20 = v26;
    }
    v21 = ObInsertObject((int)v20, 0, 3, 1, (int)&v26, (int)&v32);
    v17 = v21;
    if ( v21 >= 0 )
    {
      ObfReferenceObject(a1);
      *((_DWORD *)v26 + 2) = a1;
      IopInsertRemoveDevice(a1, (int)v26, 1);
      if ( *((_DWORD *)v26 + 9) )
        PoVolumeDevice();
      ObCloseHandle(v32);
LABEL_40:
      v22 = v26;
LABEL_41:
      if ( v28 )
      {
        ExFreePoolWithTag(v28);
        v22 = v26;
      }
      if ( v27 )
      {
        ExFreePoolWithTag(v27);
        v22 = v26;
      }
      *a7 = v22;
      return v17;
    }
    if ( v21 != -1073741771 || (a5 & 0x80) == 0 )
    {
      v22 = 0;
      v26 = 0;
      goto LABEL_41;
    }
    if ( v28 )
    {
      ExFreePoolWithTag(v28);
      v28 = 0;
    }
    a3 = v30;
    if ( v27 )
    {
      ExFreePoolWithTag(v27);
      a3 = v30;
      goto LABEL_2;
    }
  }
  v17 = IopCreateVpb(v26);
  if ( v17 >= 0 )
  {
    KeInitializeEvent((int)(v26 + 156), 1, 1);
    goto LABEL_22;
  }
  ObfDereferenceObject((int)v26);
  if ( v28 )
    ExFreePoolWithTag(v28);
  if ( v27 )
    ExFreePoolWithTag(v27);
  *a7 = 0;
  return v17;
}
