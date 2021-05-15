// KeRevertToUserGroupAffinityThread 
 
int __fastcall KeRevertToUserGroupAffinityThread(int result, int a2, int a3, int a4)
{
  _DWORD *v4; // r4
  unsigned int v5; // r5
  int v6; // r0
  int v7; // r9
  unsigned int v8; // r6
  unsigned int *v9; // r8
  unsigned int v10; // r2
  int v11; // r2
  int v12; // r2
  unsigned int v13; // r2
  bool v14; // zf
  int v15[8]; // [sp+0h] [bp-20h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v4 = (_DWORD *)result;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_DWORD *)(v5 + 0x4C) & 8) != 0
    && !(*(unsigned __int16 *)(result + 6) | *(unsigned __int16 *)(result + 10) | *(unsigned __int16 *)(result + 8)) )
  {
    if ( !*(_DWORD *)result
      || (v13 = *(unsigned __int16 *)(result + 4), v13 < (unsigned __int16)KeActiveProcessors)
      && (v14 = (*(_DWORD *)result & dword_681D78[v13]) == 0, *(_DWORD *)result &= dword_681D78[v13], !v14) )
    {
      v6 = KfRaiseIrql(2);
      v7 = v6;
      v8 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      v9 = (unsigned int *)(v5 + 44);
      do
        v10 = __ldrex(v9);
      while ( __strex(1u, v9) );
      __dmb(0xBu);
      if ( v10 )
      {
        result = sub_50A828(v6, 1);
      }
      else
      {
        if ( *v4 )
        {
          v11 = 32;
        }
        else
        {
          v11 = *(_DWORD *)(v5 + 124);
          v4 = (_DWORD *)(v5 + 340);
          *(_DWORD *)(v5 + 76) &= 0xFFFFFFF7;
        }
        v15[0] = 0;
        ((void (__fastcall *)(unsigned int, _DWORD *, int, int *))KiSetSystemAffinityThread)(v8 + 1408, v4, v11, v15);
        __dmb(0xBu);
        *v9 = 0;
        if ( (dword_682604 & 0x1000) != 0 )
          EtwTraceThreadAffinity(v5, v4, v12);
        result = KiProcessDeferredReadyList(v8 + 1408, v15, v7);
      }
    }
  }
  return result;
}
