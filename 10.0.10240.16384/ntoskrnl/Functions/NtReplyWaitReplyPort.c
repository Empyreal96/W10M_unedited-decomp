// NtReplyWaitReplyPort 
 
int __fastcall NtReplyWaitReplyPort(int a1, unsigned int a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r6
  int v6; // r5
  _DWORD *v7; // r4
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  v9[0] = (int)a3;
  v9[1] = (int)a4;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = ObReferenceObjectByHandle(a1, 1, AlpcPortObjectType, v5, (int)v9, 0);
  if ( v6 >= 0 )
  {
    v7 = (_DWORD *)v9[0];
    if ( (*(_DWORD *)(v9[0] + 244) & 6) == 2 )
    {
      ObfDereferenceObject(v9[0]);
      v6 = -1073741811;
    }
    else
    {
      v6 = LpcpReplyWaitReplyPort((_DWORD *)v9[0], a2, v5, v5);
      ObfDereferenceObject((int)v7);
    }
  }
  return v6;
}
