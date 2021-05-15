// KeSetIdealProcessorThreadByNumber 
 
int __fastcall KeSetIdealProcessorThreadByNumber(int a1, unsigned __int16 *a2, int a3, unsigned int a4)
{
  int v5; // r3
  unsigned int v6; // r1
  int v7; // r0
  unsigned int v8; // r2
  int v9; // r1
  char v10; // r3
  unsigned int v11; // r2
  unsigned int v13; // [sp+0h] [bp-8h] BYREF

  v13 = a4;
  if ( *((_BYTE *)a2 + 3) )
    goto LABEL_7;
  v5 = *a2;
  if ( *a2 || (v6 = *((unsigned __int8 *)a2 + 2), v5 = KeNumberProcessors_0, v6 >= KeNumberProcessors_0) )
    v6 = -1;
  if ( v6 == -1 )
  {
LABEL_7:
    v9 = -1073741811;
    if ( a1 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
      v8 = *(_DWORD *)(a1 + 364);
    else
      v8 = *(_DWORD *)(a1 + 124);
  }
  else
  {
    v7 = KeSetIdealProcessorThreadEx(a1, v6, &v13, v5);
    v8 = v13;
    v9 = v7;
  }
  if ( !v8 )
  {
    v10 = 0;
    *(_BYTE *)(a3 + 3) = 0;
    *(_WORD *)a3 = 0;
LABEL_15:
    *(_BYTE *)(a3 + 2) = v10;
    return v9;
  }
  if ( v8 < 0x20 )
  {
    v11 = KiProcessorIndexToNumberMappingTable[v8];
    if ( v11 )
    {
      *(_BYTE *)(a3 + 3) = 0;
      *(_WORD *)a3 = v11 >> 6;
      v10 = v11 & 0x3F;
      goto LABEL_15;
    }
  }
  return v9;
}
