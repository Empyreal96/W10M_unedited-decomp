// ObpCaptureObjectName 
 
int __fastcall ObpCaptureObjectName(char a1, _DWORD *a2, int a3, int a4)
{
  int v5; // r6
  int v6; // r0
  unsigned int v7; // r10
  unsigned int v8; // r4
  unsigned int v9; // r6
  _DWORD *v10; // r5
  _DWORD *v11; // r9
  int v13; // [sp+8h] [bp-28h]
  int v14; // [sp+8h] [bp-28h]

  *(_DWORD *)(a3 + 4) = 0;
  *(_WORD *)a3 = 0;
  *(_WORD *)(a3 + 2) = 0;
  v5 = 0;
  if ( !a1 || (v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A)) == 0 )
  {
    v7 = a2[1];
    v8 = (unsigned __int16)*a2;
LABEL_12:
    if ( v8 )
    {
      if ( (v8 & 1) != 0 || v8 == 65534 )
      {
        v5 = -1073741773;
      }
      else
      {
        v9 = v8 + 2;
        if ( v8 + 2 >= v8 )
        {
          if ( a4 && v9 <= 0xF8 )
          {
            LOWORD(v9) = 248;
            v11 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
            v13 = v11[714];
            ++*(_DWORD *)(v13 + 12);
            v10 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v13);
            if ( v10
              || (++*(_DWORD *)(v13 + 16),
                  v14 = v11[715],
                  ++*(_DWORD *)(v14 + 12),
                  (v10 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)v14)) != 0)
              || (++*(_DWORD *)(v14 + 16),
                  (v10 = (_DWORD *)(*(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(v14 + 40))(
                                     *(_DWORD *)(v14 + 28),
                                     *(_DWORD *)(v14 + 36),
                                     *(_DWORD *)(v14 + 32))) != 0) )
            {
              *v10 = v11[357];
            }
          }
          else
          {
            v10 = (_DWORD *)ExAllocatePoolWithTag(1, v8 + 2, 1833853519);
          }
          *(_WORD *)a3 = v8;
          *(_WORD *)(a3 + 2) = v9;
          *(_DWORD *)(a3 + 4) = v10;
        }
        else
        {
          v10 = 0;
        }
        if ( v10 )
        {
          memmove((int)v10, v7, v8);
          *((_WORD *)v10 + (v8 >> 1)) = 0;
          v5 = 0;
        }
        else
        {
          v5 = -1073741670;
        }
      }
    }
    return v5;
  }
  if ( (unsigned int)a2 >= MmUserProbeAddress )
    a2 = (_DWORD *)MmUserProbeAddress;
  v7 = a2[1];
  v8 = (unsigned __int16)*a2;
  if ( (unsigned __int16)*a2 )
  {
    if ( (v7 & 1) != 0 )
      ExRaiseDatatypeMisalignment(v6);
    if ( v8 + v7 > MmUserProbeAddress || v8 + v7 < v7 )
      *(_BYTE *)MmUserProbeAddress = 0;
    goto LABEL_12;
  }
  return v5;
}
