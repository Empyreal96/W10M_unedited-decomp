// ExpStringCapture 
 
int __fastcall ExpStringCapture(int *a1, unsigned __int16 *a2)
{
  int *v3; // r9
  unsigned int v4; // r6
  int v5; // r0
  int v6; // r5
  unsigned int v8; // r2
  unsigned __int16 *_2C; // [sp+2Ch] [bp+Ch]

  _2C = a2;
  v3 = a1;
  v4 = *a2;
  if ( (v4 & 1) != 0 || !*a2 )
    return -1073741811;
  v5 = ExAllocatePoolWithQuotaTag(9u, v4 + 2, 1347639365);
  v6 = v5;
  if ( !v5 )
    return -1073741801;
  if ( v4 )
  {
    v8 = *((_DWORD *)a2 + 1);
    if ( (v8 & 1) != 0 )
      ExRaiseDatatypeMisalignment(v5);
    if ( v8 + v4 > MmUserProbeAddress || v8 + v4 < v8 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  memmove(v5, *((_DWORD *)a2 + 1), v4);
  *(_WORD *)(v6 + 2 * (v4 >> 1)) = 0;
  *v3 = v6;
  return 0;
}
