// PfpPrefetchRequest 
 
int __fastcall PfpPrefetchRequest(_DWORD *a1, int a2)
{
  int v2; // r9
  _DWORD *v4; // r4
  int v5; // r10
  int v6; // r5
  unsigned int v7; // r1
  int v8; // r0
  int v9; // r3
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r2
  _DWORD *v13; // r8
  unsigned int v14; // r1
  unsigned int v15; // r3
  _DWORD *v16; // r9
  int v18; // [sp+8h] [bp-38h] BYREF
  int v19; // [sp+Ch] [bp-34h]
  int v20; // [sp+10h] [bp-30h]
  unsigned int v21; // [sp+14h] [bp-2Ch]
  unsigned int v22; // [sp+18h] [bp-28h]
  _DWORD *v23; // [sp+1Ch] [bp-24h]
  _DWORD *v24; // [sp+20h] [bp-20h]
  _DWORD *anonymous7; // [sp+48h] [bp+8h]
  int anonymous8; // [sp+4Ch] [bp+Ch]

  anonymous8 = a2;
  v2 = (char)a2;
  v19 = (char)a2;
  LOBYTE(anonymous8) = a2;
  anonymous7 = a1;
  v4 = 0;
  v5 = 0;
  v18 = 0;
  if ( a1[2] != 5 )
  {
    v6 = -1073741821;
    goto LABEL_24;
  }
  v7 = a1[4];
  if ( v7 < 0x68 )
  {
    v6 = -1073741306;
    goto LABEL_24;
  }
  v8 = ExAllocatePoolWithTag(1, v7, 1364354640);
  v4 = (_DWORD *)v8;
  v20 = v8;
  if ( !v8 )
  {
    v6 = -1073741670;
    goto LABEL_24;
  }
  if ( v2 )
  {
    v9 = a1[4];
    if ( v9 )
    {
      v10 = a1[3];
      if ( (v10 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v8);
      if ( v10 + v9 > MmUserProbeAddress || v10 + v9 < v10 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  memmove(v8, a1[3], a1[4]);
  if ( PfPrefetchRequestVerify(v4, a1[4]) )
  {
    v6 = -1073741701;
    goto LABEL_24;
  }
  v11 = v4[13];
  if ( v11 )
  {
    v6 = ObReferenceObjectByHandle(v11, 1, ExEventObjectType, v2, (int)&v18, 0);
    v4[13] = v18;
    if ( v6 < 0 )
      goto LABEL_24;
    v5 = 1;
    v18 = 1;
  }
  v6 = PfpPrefetchRequestPerform(v4);
  v12 = v4[9];
  v13 = (_DWORD *)((char *)v4 + v12);
  v14 = (unsigned int)&v4[8 * v4[3]] + v12;
  v21 = v14;
  v15 = a1[3];
  v22 = v15;
  v16 = (_DWORD *)(v12 + v15);
  if ( v19 )
  {
    ProbeForWrite(v15, a1[4], 4);
    v14 = v21;
  }
  while ( (unsigned int)v13 < v14 )
  {
    *v16 ^= ((unsigned __int8)*v16 ^ (unsigned __int8)*v13) & 8;
    v13 += 8;
    v23 = v13;
    v16 += 8;
    v24 = v16;
  }
  memmove(v22 + 60, (int)(v4 + 15), 0x2Cu);
LABEL_24:
  if ( v5 )
    ObfDereferenceObject(v4[13]);
  if ( v4 )
    ExFreePoolWithTag((unsigned int)v4);
  return v6;
}
