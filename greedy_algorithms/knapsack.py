from __future__ import print_function


class Item(object):
    def __init__(self, profit, weight):
        self.profit = profit
        self.weight = weight

    def set_profit_by_weight(self):
        self.profit_by_weight = float(self.profit)/self.weight


def greedy_knapsack(item_list, capacity):
    # sort the item_list in decreasing according to the profit_by_weight ratio
    item_list.sort(key=lambda x: [x.profit_by_weight], reverse=True)

    # itit profit
    total_profit = 0
    # start adding objects to sack, so iterate over the list
    for i in xrange(len(item_list)):
        if capacity > item_list[i].weight:
            total_profit += item_list[i].profit
            capacity -= item_list[i].weight
        # breaking if we see capacity goes lesss than item.weight
        else:
            break
    # now fill the fractional part left in sack
    if capacity > 0:
        total_profit += capacity * item_list[i].profit_by_weight
    # return total_profit
    return total_profit


def construct_item(profit_list, weight_list):
    if len(profit_list) != len(weight_list):
        return False

    # make a item list
    item = list()
    # iterate of profit_list and weight_list and construct the list
    for i in xrange(len(profit_list)):
        item.append(Item(profit_list[i], weight_list[i]))
        item[-1].set_profit_by_weight()
    return item


if __name__ == '__main__':
    capacity = int(raw_input('enter sack capacity:\n'))
    profit_list = list(input('input profit list separated by ,:\n'))
    weight_list = list(input('input weight list separated by ,:\n'))
    item_list = construct_item(profit_list, weight_list)
    if item_list is False:
        print ('enter the profit list and weight list appropriately\n')
    else:
        profit = greedy_knapsack(item_list, capacity)
        print ('Profit is: %.2f' % profit)
