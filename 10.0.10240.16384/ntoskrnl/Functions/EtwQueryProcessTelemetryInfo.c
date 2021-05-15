// EtwQueryProcessTelemetryInfo 
 
int __fastcall EtwQueryProcessTelemetryInfo(_DWORD *a1, int a2, unsigned int a3, char a4, unsigned int *a5)
{
  _BYTE *v6; // r4
  unsigned __int16 *v8; // r9
  int v9; // r10
  int v10; // r5
  unsigned int *v11; // r0
  unsigned int v12; // r4
  unsigned int v13; // r1
  unsigned int v14; // r9
  int v15; // r2
  unsigned int v16; // r4
  int v17; // r3
  int v18; // r2
  int v19; // r2
  int v20; // r2
  int v21; // r2
  unsigned int v22; // r9
  int v23; // r4
  unsigned __int16 *v24; // r9
  int v25; // r4
  int v26; // r4
  int v27; // r0
  unsigned int v30; // [sp+4h] [bp-244h] BYREF
  int v31; // [sp+8h] [bp-240h] BYREF
  unsigned int v32; // [sp+Ch] [bp-23Ch]
  int v33; // [sp+10h] [bp-238h]
  int v34; // [sp+14h] [bp-234h]
  int v35; // [sp+18h] [bp-230h] BYREF
  int v36; // [sp+1Ch] [bp-22Ch]
  int v37; // [sp+20h] [bp-228h]
  _DWORD *v38; // [sp+24h] [bp-224h]
  unsigned __int16 *v39; // [sp+28h] [bp-220h]
  int v40; // [sp+2Ch] [bp-21Ch]
  int v41; // [sp+30h] [bp-218h]
  unsigned int *v42; // [sp+34h] [bp-214h]
  unsigned int v43; // [sp+38h] [bp-210h] BYREF
  unsigned int v44; // [sp+3Ch] [bp-20Ch]
  int v45; // [sp+40h] [bp-208h] BYREF
  int v46; // [sp+140h] [bp-108h] BYREF
  _BYTE v47[24]; // [sp+1C8h] [bp-80h] BYREF
  _BYTE v48[104]; // [sp+1E0h] [bp-68h] BYREF

  v41 = a4;
  v6 = (_BYTE *)a2;
  v38 = a1;
  v42 = a5;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v35 = 0;
  v34 = 0;
  v36 = 0;
  v8 = (unsigned __int16 *)a1[95];
  v39 = v8;
  v9 = PsReferencePrimaryToken((int)a1);
  v40 = v9;
  v30 = 0;
  EtwpQueryTokenPackageInfo(v9, (int)&v43, &v30);
  v10 = SeQueryUserSidToken(v9, (int)v48, 0x44u, &v30);
  if ( v10 < 0 )
  {
    v16 = v32;
  }
  else
  {
    if ( PsAcquireProcessExitSynchronization((int)a1) >= 0 )
    {
      KiStackAttachProcess((int)a1, 0, (int)v47);
      EtwpQueryProcessOtherInfo((int)a1, &v35);
      EtwpQueryProcessCommandLine((int)a1, (int)&v31);
      KiUnstackDetachProcess((unsigned int)v47, 0);
      v11 = a1 + 43;
      __pld(a1 + 43);
      v12 = a1[43] & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v13 = __ldrex(v11);
      while ( v13 == v12 && __strex(v12 - 2, v11) );
      if ( v13 != v12 )
        ExfReleaseRundownProtection((unsigned __int8 *)v11);
      v34 = v36;
      v33 = v35;
      v6 = (_BYTE *)a2;
    }
    v14 = v43 + (unsigned __int16)v31 + *v8 + v44 + v30 + 100;
    *v42 = v14;
    if ( v41 )
      ProbeForWrite((unsigned int)v6, a3, 8);
    if ( v14 >= a3 )
      v15 = a3;
    else
      v15 = v14;
    memset(v6, 0, v15);
    if ( a3 >= 0x60 )
    {
      *(_DWORD *)a2 = 96;
      *(_DWORD *)(a2 + 4) = a1[44];
      v17 = a1[205] | (MEMORY[0xFFFF92C4] << 16);
      *(_DWORD *)(a2 + 8) = a1[204];
      *(_DWORD *)(a2 + 12) = v17;
      v18 = a1[51];
      *(_DWORD *)(a2 + 16) = a1[50];
      *(_DWORD *)(a2 + 20) = v18;
      v19 = a1[207];
      *(_DWORD *)(a2 + 24) = a1[206];
      *(_DWORD *)(a2 + 28) = v19;
      v20 = a1[209];
      *(_DWORD *)(a2 + 32) = a1[208];
      *(_DWORD *)(a2 + 36) = v20;
      v21 = a1[205];
      *(_DWORD *)(a2 + 40) = a1[204];
      *(_DWORD *)(a2 + 44) = v21;
      *(_QWORD *)(a2 + 48) = MmGetSessionCreateTime((int)a1);
      *(_DWORD *)(a2 + 56) = PsGetProcessSessionId((int)a1);
      *(_DWORD *)(a2 + 60) = MEMORY[0xFFFF92C4];
      *(_DWORD *)(a2 + 64) = v33;
      *(_DWORD *)(a2 + 68) = v34;
      if ( a3 >= v14 )
      {
        *(_DWORD *)(a2 + 72) = 96;
        v22 = v30;
        memmove(a2 + 96, (int)v48, v30);
        v23 = a2 + 96 + v22;
        *(_DWORD *)(a2 + 76) = v22 + 96;
        v24 = v39;
        memmove(v23, *((_DWORD *)v39 + 1), *v39);
        v25 = *v24 + v23 + 2;
        *(_DWORD *)(a2 + 80) = v25 - a2;
        memmove(v25, (int)&v45, v43);
        v26 = v25 + v43;
        *(_DWORD *)(a2 + 84) = v26 - a2;
        memmove(v26, (int)&v46, v44);
        v27 = v26 + v44;
        *(_DWORD *)(a2 + 88) = v26 + v44 - a2;
        v16 = v32;
        memmove(v27, v32, (unsigned __int16)v31);
        v10 = 0;
      }
      else
      {
        v10 = -2147483643;
        v37 = -2147483643;
        v16 = v32;
      }
    }
    else
    {
      v10 = -1073741820;
      v37 = -1073741820;
      v16 = v32;
    }
  }
  if ( v16 )
    ExFreePoolWithTag(v16);
  if ( v9 )
    ObFastDereferenceObject(a1 + 61, v9);
  return v10;
}
