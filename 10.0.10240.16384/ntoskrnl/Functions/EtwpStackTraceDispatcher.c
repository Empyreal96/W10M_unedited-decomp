// EtwpStackTraceDispatcher 
 
int __fastcall EtwpStackTraceDispatcher(int result, _QWORD *a2, int a3, unsigned int a4)
{
  unsigned int v4; // r5
  int v5; // r8
  unsigned int v7; // r9
  int v8; // r6
  unsigned int v9; // r7
  int v10; // r3

  v4 = a4;
  v5 = a3;
  v7 = result;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (a4 & 0x4000) == 0 || *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x58C) != v8 )
  {
    if ( !a3 )
      v5 = v8;
    if ( (a4 & 0x3000) != 4096 )
      goto LABEL_28;
    if ( (*(_DWORD *)(v8 + 76) & 0x400) == 0 && v8 == v5 )
    {
      if ( (*(_DWORD *)(v8 + 960) & 1) != 0 )
      {
        v4 = a4 & 0xFFFFEFFF;
      }
      else
      {
        result = KeAreInterruptsEnabled();
        if ( result )
        {
          result = KeGetCurrentIrql(result);
          v9 = result;
        }
        else
        {
          v9 = 15;
        }
        if ( v9 < 2 )
        {
          if ( (v7 & 0x1000000) == 0 )
          {
            result = MmCanThreadFault();
            if ( result )
            {
              if ( !*(_BYTE *)(v8 + 974)
                && *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) != 1
                && (v4 & 0x1000000) == 0
                && !((unsigned __int8)(*(_BYTE *)(v8 + 76) & 0x20) >> 5) )
              {
                goto LABEL_28;
              }
            }
          }
          v4 &= 0xFFFFEFFF;
        }
        else
        {
          v4 &= 0xFFFFEFFF;
          v10 = *(unsigned __int8 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x590);
          if ( v10 && ((v4 & 0x8000) == 0 || v10 != 1) )
            goto LABEL_28;
        }
        result = EtwpQueueStackWalkApc(v8, v9, v7, a2);
      }
    }
    else
    {
      v4 = a4 & 0xFFFFEFFF;
    }
LABEL_28:
    if ( (v4 & 0x1800) != 0 )
      result = EtwpTraceStackWalk(v7, v4, v5, a2);
  }
  return result;
}
