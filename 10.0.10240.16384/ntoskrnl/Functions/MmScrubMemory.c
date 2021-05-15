// MmScrubMemory 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MmScrubMemory(int a1, _DWORD *a2, int a3, int a4)
{
  char v5; // r3
  int v6; // r5
  unsigned int v7; // r5
  unsigned int *v8; // r0
  unsigned int v9; // r6
  int v10; // r8
  unsigned int v11; // r7
  unsigned int i; // r4 OVERLAPPED
  int (__fastcall *v13)(int *); // r3
  unsigned int v14; // r1
  int v16[8]; // [sp+8h] [bp-20h] BYREF

  v16[0] = a4;
  *a2 = 0;
  v5 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v6 = ObReferenceObjectByHandle(a1, 1, ExEventObjectType, v5, (int)v16, 0);
  if ( v6 >= 0 )
  {
    v7 = (unsigned __int16)KeNumberNodes;
    v8 = (unsigned int *)ExAllocatePoolWithTag(512, 24 * (unsigned __int16)KeNumberNodes + 28, 1667450189);
    v9 = (unsigned int)v8;
    v10 = v16[0];
    if ( v8 )
    {
      *v8 = v7;
      KeInitializeGate((int)(v8 + 1));
      v11 = 0;
      *(_DWORD *)(v9 + 20) = v10;
      *(_DWORD *)(v9 + 24) = 0;
      for ( i = v9 + 28; v11 < v7; i += 24 )
      {
        v13 = MiScrubMemoryWorker;
        *(_DWORD *)i = v11;
        *(_DWORD *)(i + 4) = 0;
        *(_QWORD *)(i + 16) = *(_QWORD *)(&i - 1);
        *(_DWORD *)(i + 8) = 0;
        ExQueueWorkItemEx((_DWORD *)(i + 8), 4, v11++);
      }
      v16[0] = 0;
      v6 = MiScrubProcesses(v10, v16);
      KeWaitForGate(v9 + 4, 0);
      if ( v6 >= 0 )
      {
        while ( 1 )
        {
          i -= 24;
          if ( *(int *)(i + 4) < 0 )
            break;
          if ( !--v11 )
            goto LABEL_11;
        }
        v6 = *(_DWORD *)(i + 4);
      }
LABEL_11:
      *a2 = v16[0] + *(_DWORD *)(v9 + 24);
      ExFreePoolWithTag(v9);
      if ( *(_DWORD *)(v10 + 4) )
      {
        v6 = -1073741248;
      }
      else
      {
        do
          v14 = __ldrex((unsigned int *)&dword_634420);
        while ( __strex(v14 + 1, (unsigned int *)&dword_634420) );
      }
    }
    else
    {
      v6 = -1073741670;
    }
    ObfDereferenceObject(v10);
  }
  return v6;
}
