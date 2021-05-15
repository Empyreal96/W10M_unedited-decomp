// IoCreateController 
 
_BYTE *__fastcall IoCreateController(int a1)
{
  int v1; // r3
  int v2; // r4
  _BYTE *v4; // [sp+18h] [bp-28h] BYREF
  int v5; // [sp+1Ch] [bp-24h] BYREF
  int v6[8]; // [sp+20h] [bp-20h] BYREF

  v6[0] = 24;
  v6[1] = 0;
  if ( IopCaseInsensitive )
    v1 = 64;
  else
    v1 = 0;
  v6[3] = v1 | 0x200;
  v6[2] = 0;
  v6[4] = 0;
  v6[5] = 0;
  v2 = a1 + 40;
  if ( ObCreateObject(0, (_DWORD *)IoControllerObjectType, (int)v6, 0, 0, a1 + 40, 0, 0, &v4) < 0
    || ObInsertObject((int)v4, 0, 3, 1, (int)&v4, (int)&v5) < 0 )
  {
    return 0;
  }
  ObCloseHandle(v5);
  memset(v4, 0, v2);
  *(_WORD *)v4 = 2;
  *((_WORD *)v4 + 1) = v2;
  *((_DWORD *)v4 + 1) = v4 + 40;
  KeInitializeDeviceQueue((int)(v4 + 8));
  return v4;
}
