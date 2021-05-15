// KdpGetContext 
 
int __fastcall KdpGetContext(int result, int a2, _BYTE *a3)
{
  int v3; // r6
  unsigned int v4; // r3
  int v7; // r2
  int v8; // r9
  _DWORD *v9; // r3
  _DWORD *v10; // r4
  int v11; // r3

  v3 = result;
  v4 = *(unsigned __int16 *)(result + 6);
  if ( v4 >= 0x20 || !*(&KiProcessorBlock + v4) )
    goto LABEL_8;
  result = KeGetCurrentProcessorNumberEx(0);
  v7 = *(unsigned __int16 *)(v3 + 6);
  if ( v7 != (unsigned __int16)result )
    a3 = (_BYTE *)*((_DWORD *)*(&KiProcessorBlock + v7) + 326);
  v8 = *(_DWORD *)a3;
  if ( *(unsigned __int16 *)(a2 + 2) >= 0x1BFu )
  {
    v9 = *(_DWORD **)(a2 + 4);
    *v9 = v8;
    v9[107] = 416;
    v9[105] = 440;
    v9[106] = -416;
    v9[104] = -416;
    v10 = *(_DWORD **)(a2 + 4);
    result = KdpQuickMoveMemory((int)v10, a3, 416);
    *v10 = v8;
    *(_WORD *)a2 = 416;
    v11 = 0;
  }
  else
  {
LABEL_8:
    v11 = -1073741823;
  }
  *(_DWORD *)(v3 + 8) = v11;
  return result;
}
