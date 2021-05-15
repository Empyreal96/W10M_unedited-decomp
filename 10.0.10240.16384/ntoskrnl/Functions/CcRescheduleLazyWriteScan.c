// CcRescheduleLazyWriteScan 
 
void __fastcall __spoils<R2,R3,R12> CcRescheduleLazyWriteScan(int *a1)
{
  int v1; // r1
  int v2; // r2
  __int64 v3; // r2
  int v4; // r4
  __int64 v5; // r0
  bool v6; // cf

  if ( !CcCoalescingState )
  {
    if ( byte_632770 )
    {
      if ( a1 && ((v1 = a1[1], v2 = *a1, *a1 != -1) || v1 != 0x7FFFFFFF) && v2 | v1 )
      {
        LODWORD(v3) = v2 * KeMaximumIncrement;
        v4 = (*(_QWORD *)a1 * (unsigned __int64)(unsigned int)KeMaximumIncrement) >> 32;
        if ( v4 > 0 || v4 >= 0 && (unsigned int)v3 > 0x9896800 )
        {
          LODWORD(v3) = 160000000;
          v4 = 0;
        }
        if ( v4 < 0 || (unsigned int)v3 < (unsigned int)dword_989680 )
        {
          v4 = unk_61794C;
          LODWORD(v3) = CcIdleDelay;
        }
        if ( v4 >= 0 && (v4 > 0 || (_DWORD)v3) )
        {
          v6 = (_DWORD)v3 == 0;
          LODWORD(v3) = -(int)v3;
          v4 = -(v4 + !v6);
        }
      }
      else
      {
        v4 = unk_61794C;
        LODWORD(v3) = CcIdleDelay;
      }
      HIDWORD(v5) = 1000;
      HIDWORD(v3) = v4;
      LODWORD(v5) = &unk_632740;
      KeSetCoalescableTimer(v5, v3, 0, 0x3E8u, (int)&LazyWriter);
    }
    else
    {
      CcScheduleLazyWriteScan(0, 0);
    }
  }
}
