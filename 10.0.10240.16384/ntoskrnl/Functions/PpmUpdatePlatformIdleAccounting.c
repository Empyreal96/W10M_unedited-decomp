// PpmUpdatePlatformIdleAccounting 
 
int __fastcall PpmUpdatePlatformIdleAccounting(int result, unsigned __int64 a2)
{
  unsigned __int64 *v4; // r2
  unsigned int i; // r3
  unsigned int v6; // r1
  __int64 v7; // kr00_8
  bool v8; // cf
  int v9; // r3

  v4 = (unsigned __int64 *)&PpmIdleIntervalLimits;
  for ( i = 0; i < 0x1A; ++i )
  {
    if ( a2 < *v4 )
      break;
    v4 += 3;
  }
  if ( i >= 0x1A )
    return sub_554574();
  v6 = result + 32 * (i + 5);
  v7 = *(_QWORD *)v6;
  v8 = __CFADD__(*(_DWORD *)v6, (_DWORD)a2);
  *(_DWORD *)v6 += a2;
  v9 = *(_DWORD *)(v6 + 24);
  *(_DWORD *)(v6 + 4) = HIDWORD(a2) + v8 + HIDWORD(v7);
  *(_DWORD *)(v6 + 24) = v9 + 1;
  if ( a2 < *(_QWORD *)(v6 + 8) )
    *(_QWORD *)(v6 + 8) = a2;
  if ( a2 > *(_QWORD *)(v6 + 16) )
    *(_QWORD *)(v6 + 16) = a2;
  if ( a2 < *(_QWORD *)(result + 24) )
    *(_QWORD *)(result + 24) = a2;
  if ( a2 > *(_QWORD *)(result + 16) )
    *(_QWORD *)(result + 16) = a2;
  return result;
}
