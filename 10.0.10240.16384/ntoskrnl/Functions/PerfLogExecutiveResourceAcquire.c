// PerfLogExecutiveResourceAcquire 
 
_DWORD *__fastcall PerfLogExecutiveResourceAcquire(int a1, int a2, unsigned int a3, int a4)
{
  int v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r10
  unsigned int v11; // r4
  _DWORD *result; // r0
  int v13; // r3
  int v14; // r3
  int v15; // [sp+0h] [bp-30h]
  int v16; // [sp+4h] [bp-2Ch]
  int v17; // [sp+8h] [bp-28h]
  int v18; // [sp+Ch] [bp-24h]

  v8 = ReadTimeStampCounter();
  v10 = v9;
  v16 = v8;
  v11 = (unsigned int)KeGetPcr();
  v17 = *(unsigned __int8 *)((v11 & 0xFFFFF000) + 0x99C);
  LOWORD(v15) = *(unsigned __int8 *)((v11 & 0xFFFFF000) + 0x99C);
  v18 = *(unsigned __int8 *)((v11 & 0xFFFFF000) + 0x99D);
  HIWORD(v15) = (unsigned __int8)v18;
  ++*(_DWORD *)((v11 & 0xFFFFF000) + 0x14B0);
  result = EtwpGetTrackingLockSlotForThread(a2, a1 & 0xFFFF0000);
  if ( result )
  {
    ++*(_DWORD *)((v11 & 0xFFFFF000) + 0x14B4);
    if ( a1 == 65569 || a1 == 65601 )
    {
      v13 = result[7];
      result[2] = v16;
      result[3] = v10;
      if ( v13 && v13 == 4 )
      {
        if ( *((unsigned __int16 *)result + 10) != v17 || *((unsigned __int8 *)result + 22) != v18 )
        {
LABEL_15:
          *result = 1;
          result[1] = 0;
LABEL_18:
          result[10] = a4;
          result[5] = v15;
          goto LABEL_19;
        }
        v14 = v16 - *result;
        result[1] = (__PAIR64__(v10, v16) - *(_QWORD *)result) >> 32;
      }
      else
      {
        v14 = 0;
        result[1] = 0;
      }
      *result = v14;
      goto LABEL_18;
    }
    if ( a1 == 65585 || a1 == 65617 )
    {
      if ( result[7] )
      {
        if ( result[8] >= a3 )
        {
LABEL_20:
          result[7] = 1;
          return result;
        }
LABEL_19:
        result[8] = a3;
        goto LABEL_20;
      }
      result[2] = 2;
      result[3] = 0;
      goto LABEL_15;
    }
  }
  return result;
}
