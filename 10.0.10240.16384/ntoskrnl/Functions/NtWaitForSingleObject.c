// NtWaitForSingleObject 
 
int __fastcall NtWaitForSingleObject(int a1, _DWORD *a2, int a3, int a4)
{
  int *v4; // r5
  unsigned int v5; // r2
  int v6; // r6
  int v7; // r4
  int v8; // r10
  int v9; // lr
  signed int v10; // r0
  int v13; // [sp+18h] [bp-40h] BYREF
  __int64 v14; // [sp+20h] [bp-38h]
  int v15; // [sp+28h] [bp-30h]
  _QWORD v16[5]; // [sp+30h] [bp-28h] BYREF
  int varg_r0; // [sp+60h] [bp+8h]
  _DWORD *varg_r1; // [sp+64h] [bp+Ch]
  _QWORD *varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  v4 = (int *)a3;
  varg_r2 = (_QWORD *)a3;
  LOBYTE(varg_r1) = (_BYTE)a2;
  varg_r0 = a1;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = *(char *)(v5 + 0x15A);
  if ( v4 && *(_BYTE *)(v5 + 0x15A) )
  {
    if ( (unsigned int)v4 >= MmUserProbeAddress )
      v4 = (int *)MmUserProbeAddress;
    v14 = *(_QWORD *)v4;
    v16[0] = v14;
    v4 = (int *)v16;
    varg_r2 = v16;
  }
  v7 = ObReferenceObjectByHandleWithTag(a1, 0x100000, 0, v6, 1951883855, &v13, 0);
  if ( v7 >= 0 )
  {
    v8 = v13;
    v9 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(v8 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v8 - 12)];
    v10 = *(_DWORD *)(v9 + 16);
    if ( (v10 & 1) != 0 )
    {
      if ( (v10 & 2) != 0 )
      {
        if ( (*(_DWORD *)(*(unsigned __int16 *)(v9 + 124) + v13) & *(_DWORD *)(v9 + 120)) == *(_DWORD *)(v9 + 120) )
          v10 = *(_DWORD *)(*(unsigned __int16 *)(v9 + 126) + v13);
        else
          v10 = v10 + v13 - 3;
      }
      else
      {
        v10 = *(_DWORD *)(v10 + v13 - 1);
      }
    }
    else if ( v10 >= 0 )
    {
      v10 += v13;
    }
    v7 = KeWaitForSingleObject(v10, 6, v6, a2, v4);
    v15 = v7;
    ObfDereferenceObjectWithTag(v8);
  }
  return v7;
}
