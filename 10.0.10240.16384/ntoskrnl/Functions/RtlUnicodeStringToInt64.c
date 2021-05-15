// RtlUnicodeStringToInt64 
 
int __fastcall RtlUnicodeStringToInt64(unsigned __int16 *a1, int a2, _QWORD *a3, _DWORD *a4)
{
  unsigned int v5; // r0
  unsigned int v6; // r7
  int v8; // r1
  unsigned __int16 *v11; // r5
  int v12; // r4
  unsigned int v13; // r4
  __int64 v14; // r0
  int result; // r0
  int v16; // [sp+8h] [bp-B0h] BYREF
  unsigned __int16 *v17; // [sp+Ch] [bp-ACh] BYREF
  char v18[168]; // [sp+10h] [bp-A8h] BYREF

  v5 = *a1;
  v6 = a1[1];
  v8 = *((_DWORD *)a1 + 1);
  v11 = (unsigned __int16 *)v8;
  if ( v6 < v5 + 2 || *(_WORD *)(v8 + 2 * (v6 >> 1) - 2) )
  {
    v12 = v5 >> 1;
    if ( v5 >> 1 >= 0x40 )
      v12 = 64;
    v13 = 2 * v12;
    v11 = (unsigned __int16 *)v18;
    memmove((int)v18, v8, v13);
    if ( v13 >= 0x82 )
      _report_rangecheckfailure();
    *(_WORD *)&v18[v13] = 0;
  }
  v16 = 0;
  LODWORD(v14) = wcstoxq(0, v11, &v17, a2, 0, &v16);
  *a3 = v14;
  if ( a4 )
    *a4 = *((_DWORD *)a1 + 1) + 2 * (v17 - v11);
  if ( v16 )
    result = -1073741675;
  else
    result = 0;
  return result;
}
