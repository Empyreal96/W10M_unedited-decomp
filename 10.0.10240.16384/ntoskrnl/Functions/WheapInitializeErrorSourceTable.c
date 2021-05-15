// WheapInitializeErrorSourceTable 
 
int __fastcall WheapInitializeErrorSourceTable(unsigned int a1, _DWORD *a2)
{
  unsigned int i; // r7
  _BYTE *v5; // r0
  _BYTE *v6; // r5
  int v7; // r0
  int v8; // r3
  int v10; // r3

  for ( i = 0; i < a1; ++i )
  {
    if ( (int)a2[2] < 12 )
    {
      v5 = (_BYTE *)ExAllocatePoolWithTag(512, 1048, 1634035799);
      v6 = v5;
      if ( !v5 )
        return -1073741670;
      memset(v5, 0, 1048);
      v7 = memmove((int)(v6 + 73), (int)a2, 0x3CCu);
      v8 = *((unsigned __int8 *)&unk_649F54 + 28 * a2[2]);
      __dmb(0xBu);
      if ( v8 )
        return sub_96FBF0(v7);
      v10 = a2[2];
      v6[72] = 1;
      *((_DWORD *)v6 + 8) = v10;
      WheapAddErrorSource(v7, (int *)v6);
      a2 = (_DWORD *)((char *)a2 + *a2);
    }
  }
  return 0;
}
