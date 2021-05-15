// KiPrepareReadyThreadForRescheduling 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiPrepareReadyThreadForRescheduling(int result, int a2, _DWORD *a3)
{
  unsigned int v3; // r5 OVERLAPPED
  unsigned int v4; // r6 OVERLAPPED
  unsigned __int64 v5; // kr00_8
  unsigned __int64 *v6; // r0

  if ( a2 < 15 && (unsigned int)(KeTickCount - 300) >= *(_DWORD *)(result + 304) )
  {
    v6 = (unsigned __int64 *)(result + 48);
    while ( 1 )
    {
      *(_QWORD *)&v3 = *v6;
      do
        v5 = __ldrexd(v6);
      while ( v5 == __PAIR64__(v4, v3) && __strexd(__PAIR64__(v4, v3), v6) );
      if ( __PAIR64__(v4, v3) == v5 )
        break;
      __dmb(0xAu);
      __yield();
    }
    result = sub_50A948();
  }
  else
  {
    *(_DWORD *)(result + 76) |= 2u;
    *(_BYTE *)(result + 132) = 7;
    *(_DWORD *)(result + 144) = *a3;
    *a3 = result + 144;
  }
  return result;
}
