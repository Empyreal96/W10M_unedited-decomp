// NtQuerySecurityObject 
 
int NtQuerySecurityObject(int a1, ...)
{
  int v1; // r2
  int v2; // r10
  _DWORD *v4; // r6
  _DWORD *v5; // r1
  int v6; // r0
  int v8; // r2
  int v9; // r5
  char v11; // [sp+18h] [bp-38h]
  int v12; // [sp+1Ch] [bp-34h] BYREF
  int v13[11]; // [sp+24h] [bp-2Ch] BYREF
  int varg_r1; // [sp+5Ch] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+5Ch] [bp+Ch]
  int varg_r2; // [sp+60h] [bp+10h]
  void *varg_r3; // [sp+64h] [bp+14h] BYREF
  va_list varg_r3a; // [sp+64h] [bp+14h]
  unsigned int v19; // [sp+68h] [bp+18h]
  va_list va2; // [sp+6Ch] [bp+1Ch] BYREF

  va_start(va2, a1);
  va_start(varg_r3a, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3a, _DWORD);
  varg_r2 = va_arg(varg_r3a, _DWORD);
  v1 = varg_r2;
  va_copy(va2, varg_r3a);
  varg_r3 = va_arg(va2, void *);
  v19 = va_arg(va2, _DWORD);
  v2 = varg_r2;
  v11 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v11 )
  {
    v4 = (_DWORD *)v19;
    v5 = (_DWORD *)v19;
    if ( v19 >= MmUserProbeAddress )
      v5 = (_DWORD *)MmUserProbeAddress;
    *v5 = *v5;
    ProbeForWrite(v1, varg_r3, 4);
  }
  else
  {
    v4 = (_DWORD *)v19;
  }
  SeQuerySecurityAccessMask(varg_r1, v13);
  v6 = ObReferenceObjectByHandle(a1, v13[0], 0, v11, &v12);
  if ( v6 < 0 )
    return v6;
  v8 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(v12 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v12 - 12)];
  v9 = (*(int (__fastcall **)(int, int, int *, int, void **, int, _DWORD, int, _DWORD))(v8 + 108))(
         v12,
         1,
         (int *)varg_r1a,
         v2,
         varg_r3a,
         v12 - 4,
         *(_DWORD *)(v8 + 76),
         v8 + 52,
         v11);
  v13[0] = v9;
  *v4 = varg_r3;
  ObfDereferenceObject(v12);
  return v9;
}
