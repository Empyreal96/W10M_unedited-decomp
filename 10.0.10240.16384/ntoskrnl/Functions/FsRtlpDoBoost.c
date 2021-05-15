// FsRtlpDoBoost 
 
_DWORD *__fastcall FsRtlpDoBoost(_DWORD *result, int a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // r6
  int v5; // r7
  int v8; // r8
  unsigned int v9; // r4
  int v10; // r3
  int v11; // r5
  unsigned int v12; // r1
  unsigned int v13; // r3

  v4 = 0;
  v5 = 0;
  v8 = (int)result;
  if ( (result[240] & 0xE00u) < 0x400 && (*a4 & 0x20) == 0 )
    v4 = 1;
  v9 = *(unsigned __int8 *)(a2 + 123);
  v10 = *(unsigned __int8 *)a3;
  v11 = v9;
  if ( v9 >= 0xF )
    v11 = 15;
  if ( v10 <= v11 )
  {
    v10 = *(unsigned __int8 *)(a2 + 123);
    if ( v9 >= 0xF )
      v10 = 15;
  }
  v12 = v10;
  *(_BYTE *)a3 = v10;
  v13 = *((unsigned __int8 *)result + 123);
  if ( v12 > v13 )
    v5 = 1;
  if ( v4 || v5 )
  {
    if ( v5 )
      result = (_DWORD *)KeSetPriorityBoost((int)result, v12, a3, (_DWORD *)v13);
    if ( v4 )
    {
      PsBoostThreadIoEx(v8, 0, 1);
      *a4 |= 0x20u;
      result = IoBoostThreadIoPriority(v8, (*(_DWORD *)(a2 + 960) >> 9) & 7, 0);
    }
  }
  return result;
}
