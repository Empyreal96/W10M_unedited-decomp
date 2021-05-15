// IopPerfLogCallEvent 
 
int *__fastcall IopPerfLogCallEvent(int a1, _DWORD *a2, int a3)
{
  int v3; // r4
  int v4; // r3
  int v5; // r3
  int v6; // r3
  int v7; // r3
  int v9[3]; // [sp+8h] [bp-30h] BYREF
  int v10; // [sp+14h] [bp-24h]
  _DWORD *v11; // [sp+18h] [bp-20h]
  int v12; // [sp+1Ch] [bp-1Ch]
  int v13[6]; // [sp+20h] [bp-18h] BYREF

  v3 = a2[24];
  v9[0] = *(unsigned __int8 *)(v3 - 40);
  v9[1] = *(unsigned __int8 *)(v3 - 39);
  v4 = *(_DWORD *)(a1 + 4 * *(unsigned __int8 *)(v3 - 40) + 56);
  v11 = a2;
  v12 = a3;
  v9[2] = v4;
  if ( (a2[2] & 8) != 0 )
  {
    v5 = a2[3];
    if ( v5 )
      v6 = *(_DWORD *)(v5 + 100);
    else
      v6 = 0;
  }
  else
  {
    v6 = a2[25];
  }
  v10 = v6;
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 + 12);
    if ( v7 )
      v10 = v7;
  }
  v13[0] = (int)v9;
  v13[1] = 0;
  v13[2] = 24;
  v13[3] = 0;
  return EtwTraceKernelEvent(v13, 1, 0x20000010u, 290, 4200450);
}
