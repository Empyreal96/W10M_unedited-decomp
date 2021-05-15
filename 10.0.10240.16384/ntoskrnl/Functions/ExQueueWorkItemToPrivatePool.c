// ExQueueWorkItemToPrivatePool 
 
int __fastcall ExQueueWorkItemToPrivatePool(_DWORD *a1, int a2, int a3, unsigned int a4)
{
  int v7; // r3
  unsigned int v8; // r3
  int result; // r0

  if ( a4 >= 8 || !a4 )
    goto LABEL_12;
  v7 = a2 + 32;
  if ( *a1 )
    KeBugCheckEx(228, 1, (int)a1, v7, 0);
  if ( v7 >= 7 && v7 < 32 || v7 >= 64 )
    KeBugCheckEx(228, 6, (int)a1, v7, 0);
  v8 = a1[2];
  if ( v8 <= MmUserProbeAddress )
    KeBugCheckEx(228, 7, (int)a1, v8, 0);
  result = ExpQueueWorkItem((int)a1, a2, 0xFFFFFFFF, a4);
  if ( !result )
LABEL_12:
    KeBugCheckEx(228, 5, (int)a1, a2 + 32, -1);
  return result;
}
