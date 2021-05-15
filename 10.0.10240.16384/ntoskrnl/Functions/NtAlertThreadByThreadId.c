// NtAlertThreadByThreadId 
 
int __fastcall NtAlertThreadByThreadId(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r4
  unsigned int v6; // r3
  int v7; // r5
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = PsLookupThreadByThreadId(a1, v9);
  if ( v5 >= 0 )
  {
    v6 = v4 & 0xFFFFFFC0;
    v7 = v9[0];
    if ( *(_DWORD *)(v9[0] + 336) == *(_DWORD *)(v6 + 336) )
    {
      KeAlertThreadByThreadId(v9[0]);
      v5 = 0;
    }
    else
    {
      v5 = -1073741790;
    }
    ObfDereferenceObject(v7);
  }
  return v5;
}
